#include "AirCraft.h"

AirCraft::AirCraft(QWidget* parent)
	: QMainWindow(parent),
	aspect_ratio(0), wing_area(0), oswald_efficiency_factor(0), gross_weight(0), zero_lift_drag_coefficient(0), 
	engine_power(0), propeller_efficiency(0), sfc(0), fuel_weight(0), altitude1(0), altitude2(0), altitude3(0)
{
	ui.setupUi(this);

	// first show the charts while nothing's here
	thrust_required_chart_draw();
	power_required_chart_draw();

	// Initialize the QDoubleValidator
	aspectRatioValidator = new QDoubleValidator(this);
	aspectRatioValidator->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
	aspectRatioValidator->setNotation(QDoubleValidator::StandardNotation);
	aspectRatioValidator->setBottom(0.0); // Assuming aspect ratio cannot be negative

	// Set the validator on all the QLineEdits
	ui.AspectRatio_lineEdit->setValidator(aspectRatioValidator);
	ui.WingArea_lineEdit->setValidator(aspectRatioValidator);
	ui.OswaldEfficiencyFactor_lineEdit->setValidator(aspectRatioValidator);
	ui.GrossWeight_llineEdit->setValidator(aspectRatioValidator);
	ui.ZeroliftDragCoefficient_lineEdit->setValidator(aspectRatioValidator);
	ui.Enginepower_lineEdit->setValidator(aspectRatioValidator);
	ui.PropellerEfficiency_lineEdit->setValidator(aspectRatioValidator);
	ui.SFC_lineEdit->setValidator(aspectRatioValidator);
	ui.FuelWeight_lineEdit->setValidator(aspectRatioValidator);

	ui.Altitude1_lineEdit->setValidator(aspectRatioValidator);
	ui.Altitude2_lineEdit->setValidator(aspectRatioValidator);
	ui.Altitude3_lineEdit->setValidator(aspectRatioValidator);

	// logo adding
	QPixmap pic("./plane_logo.png");
	int w = ui.logo->width();
	int h = ui.logo->height();
	ui.logo->setPixmap(pic.scaled(w, h, Qt::KeepAspectRatio));

	// get info from UI change
	connect(ui.AspectRatio_lineEdit, &QLineEdit::textChanged, this, &AirCraft::aspect_ratio_changed); 
	connect(ui.WingArea_lineEdit, &QLineEdit::textChanged, this, &AirCraft::wing_area_changed); 
	connect(ui.OswaldEfficiencyFactor_lineEdit, &QLineEdit::textChanged, this, &AirCraft::oswald_efficiency_factor_changed);
	connect(ui.GrossWeight_llineEdit, &QLineEdit::textChanged, this, &AirCraft::gross_weight_changed); 
	connect(ui.ZeroliftDragCoefficient_lineEdit, &QLineEdit::textChanged, this, &AirCraft::zero_lift_drag_coefficient_changed); 
	connect(ui.Enginepower_lineEdit, &QLineEdit::textChanged, this, &AirCraft::engine_power_changed); 
	connect(ui.PropellerEfficiency_lineEdit, &QLineEdit::textChanged, this, &AirCraft::propeller_efficiency_changed); 
	connect(ui.SFC_lineEdit, &QLineEdit::textChanged, this, &AirCraft::sfc_changed); 
	connect(ui.FuelWeight_lineEdit, &QLineEdit::textChanged, this, &AirCraft::fuel_weight_changed);

	connect(ui.Altitude1_lineEdit, &QLineEdit::textChanged, this, &AirCraft::altitude1_changed);
	connect(ui.Altitude2_lineEdit, &QLineEdit::textChanged, this, &AirCraft::altitude2_changed);
	connect(ui.Altitude3_lineEdit, &QLineEdit::textChanged, this, &AirCraft::altitude3_changed);

	connect(ui.dynamic_check, &QCheckBox::clicked, this, &AirCraft::on_dynamic_check_checked);
	connect(ui.draw_button, &QPushButton::clicked, this, &AirCraft::on_draw_button_clicked);
}

AirCraft::~AirCraft()
{
	
}