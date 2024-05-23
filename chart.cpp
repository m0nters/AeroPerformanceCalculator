#include "AirCraft.h"

double airDensity(double altitude) {
	const double seaLevelPressure = 101325; // Pa
	const double seaLevelTemp = 288.15; // K
	const double tempLapseRate = 0.0065; // K/m
	const double gasConstant = 8.31447; // J/(mol*K)
	const double molarMass = 0.0289644; // kg/mol
	const double gravity = 9.80665; // m/s^2

	if (altitude > 11000) { // Simplified model, not accounting for stratosphere changes
		return 0;
	}

	double temp = seaLevelTemp - tempLapseRate * altitude;
	double pressure = seaLevelPressure * pow((1 - (tempLapseRate * altitude) / seaLevelTemp), (gravity * molarMass) / (gasConstant * tempLapseRate));
	double density = (pressure * molarMass) / (gasConstant * temp);

	return density;
}

double AirCraft::thrust_required(double velocity, double altitude) {
	double W = gross_weight + fuel_weight;
	return 0.5 * airDensity(altitude) * pow(velocity, 2) * wing_area * zero_lift_drag_coefficient + (2 * W * W) / (airDensity(altitude) * pow(velocity, 2) * wing_area * aspect_ratio * M_PI * oswald_efficiency_factor);
}

double AirCraft::power_required(double velocity, double altitude) {
	return thrust_required(velocity, altitude) * velocity;
}

double const RANGE_MIN = 0;
double const RANGE_MAX = 500;
double const STEP = (RANGE_MAX - RANGE_MIN) / 400;

void AirCraft::thrust_required_chart_draw() {
	if (thrustRequiredSeries_altitude1_trashholder) { // since they are all initialized at the same time so we can just check one of them
		delete thrustRequiredSeries_altitude1_trashholder;
		delete thrustRequiredSeries_altitude2_trashholder;
		delete thrustRequiredSeries_altitude3_trashholder;
		delete thrustRequiredChart_trashholder;
		delete thrustRequiredChartView_trashholder;
	}

	QLineSeries* thrustRequiredSeries_altitude1 = new QLineSeries();
	QLineSeries* thrustRequiredSeries_altitude2 = new QLineSeries();
	QLineSeries* thrustRequiredSeries_altitude3 = new QLineSeries();
	QChart* thrustRequiredChart = new QChart();
	QChartView* thrustRequiredChartView = new QChartView(thrustRequiredChart);

	// preventing memory leak
	thrustRequiredSeries_altitude1_trashholder = thrustRequiredSeries_altitude1;
	thrustRequiredSeries_altitude2_trashholder = thrustRequiredSeries_altitude2;
	thrustRequiredSeries_altitude3_trashholder = thrustRequiredSeries_altitude3;
	thrustRequiredChart_trashholder = thrustRequiredChart;
	thrustRequiredChartView_trashholder = thrustRequiredChartView;

	thrustRequiredSeries_altitude1->setName(QString::fromStdString(std::to_string((int)altitude1) + "m"));
	thrustRequiredSeries_altitude2->setName(QString::fromStdString(std::to_string((int)altitude2) + "m"));
	thrustRequiredSeries_altitude3->setName(QString::fromStdString(std::to_string((int)altitude3) + "m"));

	for (double i = RANGE_MIN; i <= RANGE_MAX; i += STEP) {
		thrustRequiredSeries_altitude1->append(i, thrust_required(i, altitude1));
		thrustRequiredSeries_altitude2->append(i, thrust_required(i, altitude2));
		thrustRequiredSeries_altitude3->append(i, thrust_required(i, altitude3));
	}

	thrustRequiredChart->addSeries(thrustRequiredSeries_altitude1);
	thrustRequiredChart->addSeries(thrustRequiredSeries_altitude2);
	thrustRequiredChart->addSeries(thrustRequiredSeries_altitude3);
	thrustRequiredChart->createDefaultAxes();
	thrustRequiredChart->legend()->setAlignment(Qt::AlignBottom);
	thrustRequiredChart->setTheme(QChart::ChartThemeDark);
	thrustRequiredChart->axisX()->setRange(RANGE_MIN, RANGE_MAX);
	thrustRequiredChart->axisX()->setTitleText("Velocity (m/s)");

	thrustRequiredChartView->setRenderHint(QPainter::Antialiasing);
	thrustRequiredChartView->setParent(ui.thrust_required_chart);
	thrustRequiredChartView->resize(ui.thrust_required_chart->size());
	thrustRequiredChartView->show();
}

void AirCraft::power_required_chart_draw() {
	if (powerRequiredSeries_altitude1_trashholder) {
		delete powerRequiredSeries_altitude1_trashholder;
		delete powerRequiredSeries_altitude2_trashholder;
		delete powerRequiredSeries_altitude3_trashholder;
		delete powerRequiredChart_trashholder;
		delete powerRequiredChartView_trashholder;
	}

	QLineSeries* powerRequiredSeries_altitude1 = new QLineSeries();
	QLineSeries* powerRequiredSeries_altitude2 = new QLineSeries();
	QLineSeries* powerRequiredSeries_altitude3 = new QLineSeries();
	QChart* powerRequiredChart = new QChart();
	QChartView* powerRequiredChartView = new QChartView(powerRequiredChart);

	// preventing memory leak
	powerRequiredSeries_altitude1_trashholder = powerRequiredSeries_altitude1;
	powerRequiredSeries_altitude2_trashholder = powerRequiredSeries_altitude2;
	powerRequiredSeries_altitude3_trashholder = powerRequiredSeries_altitude3;
	powerRequiredChart_trashholder = powerRequiredChart;
	powerRequiredChartView_trashholder = powerRequiredChartView;

	powerRequiredSeries_altitude1->setName(QString::fromStdString(std::to_string((int)altitude1) + "m"));
	powerRequiredSeries_altitude2->setName(QString::fromStdString(std::to_string((int)altitude2) + "m"));
	powerRequiredSeries_altitude3->setName(QString::fromStdString(std::to_string((int)altitude3) + "m"));

	for (double i = RANGE_MIN; i <= RANGE_MAX; i += STEP) {
		powerRequiredSeries_altitude1->append(i, power_required(i, altitude1));
		powerRequiredSeries_altitude2->append(i, power_required(i, altitude2));
		powerRequiredSeries_altitude3->append(i, power_required(i, altitude3));
	}

	powerRequiredChart->addSeries(powerRequiredSeries_altitude1);
	powerRequiredChart->addSeries(powerRequiredSeries_altitude2);
	powerRequiredChart->addSeries(powerRequiredSeries_altitude3);
	powerRequiredChart->createDefaultAxes();
	powerRequiredChart->legend()->setAlignment(Qt::AlignBottom);
	powerRequiredChart->setTheme(QChart::ChartThemeDark);
	powerRequiredChart->axisX()->setRange(RANGE_MIN, RANGE_MAX);
	powerRequiredChart->axisX()->setTitleText("Velocity (m/s)");

	powerRequiredChartView->setRenderHint(QPainter::Antialiasing);
	powerRequiredChartView->setParent(ui.power_required_chart);
	powerRequiredChartView->resize(ui.power_required_chart->size());
	powerRequiredChartView->show();
}