#pragma once

#include <QtWidgets/QMainWindow>
#include <qpixmap.h>
#include <QtCharts>
#include <qvalidator.h>
#include <QKeyEvent>
#include <qtooltip.h>
#include <qchartview.h>
#include <cmath>
#include "ui_AirCraft.h"

class AirCraft : public QMainWindow
{
	Q_OBJECT

public:
	AirCraft(QWidget* parent = nullptr);
	void thrust_required_chart_draw();
	void power_required_chart_draw();

	double thrust_required(double velocity, double altitude);
	double power_required(double velocity, double altitude);

	~AirCraft();

public slots:
	void aspect_ratio_changed(const QString& text);
	void wing_area_changed(const QString& text);
	void oswald_efficiency_factor_changed(const QString& text);
	void gross_weight_changed(const QString& text);
	void zero_lift_drag_coefficient_changed(const QString& text);
	void engine_power_changed(const QString& text);
	void propeller_efficiency_changed(const QString& text);
	void sfc_changed(const QString& text);
	void fuel_weight_changed(const QString& text);

	void altitude1_changed(const QString& text);
	void altitude2_changed(const QString& text);
	void altitude3_changed(const QString& text);
	// =================
	void on_dynamic_check_checked();
	void on_draw_button_clicked();
private:
	Ui::AirCraftClass ui;
	QDoubleValidator* aspectRatioValidator; // Add a QDoubleValidator

	// member variables
	double aspect_ratio;
	double wing_area;
	double oswald_efficiency_factor;
	double gross_weight;
	double zero_lift_drag_coefficient;
	double engine_power;
	double propeller_efficiency;
	double sfc;
	double fuel_weight;

	double altitude1;
	double altitude2;
	double altitude3;

	std::string info_altitude1_str;
	std::string info_altitude2_str;
	std::string info_altitude3_str;
};