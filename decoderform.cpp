//
// Created by Kevin Chang on 2/5/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DecoderForm.h" resolved

#include "decoderform.h"
#include "ui_DecoderForm.h"
#include <QLabel>
#include <QGridLayout>

DecoderForm::DecoderForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::DecoderForm) {
  ui->setupUi(this);

  auto *mainLayout = new QGridLayout;

  mainLayout->addWidget(inputBox());
}

DecoderForm::~DecoderForm() {
  delete ui;
}

auto DecoderForm::inputBox() -> QLabel * {
  auto inputBoxLabel = new QLabel(this);
  inputBoxLabel->setText("Input text");

  return inputBoxLabel;
}
