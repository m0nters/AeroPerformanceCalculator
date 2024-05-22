#include "AirCraft.h"
#include <random>

void AirCraft::on_dynamic_check_checked() {
	if (ui.dynamic_check->isChecked()) {
		ui.draw_button->setEnabled(false);
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
	else
		ui.draw_button->setEnabled(true);
}

void AirCraft::on_draw_button_clicked() {
	thrust_required_chart_draw();
	power_required_chart_draw();
}

void AirCraft::aspect_ratio_changed(const QString& text) {
	bool ok;
	double new_aspect_ratio = text.toDouble(&ok);
	if (ok)
		aspect_ratio = new_aspect_ratio;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::wing_area_changed(const QString& text) {
	bool ok;
	double new_wing_area = text.toDouble(&ok);
	if (ok)
		wing_area = new_wing_area;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::oswald_efficiency_factor_changed(const QString& text) {
	bool ok;
	double new_oswald_efficiency_factor = text.toDouble(&ok);
	if (ok)
		oswald_efficiency_factor = new_oswald_efficiency_factor;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::gross_weight_changed(const QString& text) {
	bool ok;
	double new_gross_weight = text.toDouble(&ok);
	if (ok)
		gross_weight = new_gross_weight;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::zero_lift_drag_coefficient_changed(const QString& text) {
	bool ok;
	double new_zero_lift_drag_coefficient = text.toDouble(&ok);
	if (ok)
		zero_lift_drag_coefficient = new_zero_lift_drag_coefficient;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::engine_power_changed(const QString& text) {
	bool ok;
	double new_engine_power = text.toDouble(&ok);
	if (ok)
		engine_power = new_engine_power;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::propeller_efficiency_changed(const QString& text) {
	bool ok;
	double new_propeller_efficiency = text.toDouble(&ok);
	if (ok)
		propeller_efficiency = new_propeller_efficiency;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::sfc_changed(const QString& text) {
	bool ok;
	double new_sfc = text.toDouble(&ok);
	if (ok)
		sfc = new_sfc;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::fuel_weight_changed(const QString& text) {
	bool ok;
	double new_fuel_weight = text.toDouble(&ok);
	if (ok)
		fuel_weight = new_fuel_weight;

	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::altitude1_changed(const QString& text) {
	bool ok;
	double new_altitude1 = text.toDouble(&ok);
	if (ok)
		altitude1 = new_altitude1;
	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::altitude2_changed(const QString& text) {
	bool ok;
	double new_altitude2 = text.toDouble(&ok);
	if (ok)
		altitude2 = new_altitude2;
	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}

void AirCraft::altitude3_changed(const QString& text) {
	bool ok;
	double new_altitude3 = text.toDouble(&ok);
	if (ok)
		altitude3 = new_altitude3;
	if (ui.dynamic_check->isChecked()) {
		thrust_required_chart_draw();
		power_required_chart_draw();
	}
}