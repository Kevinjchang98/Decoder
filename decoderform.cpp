//
// Created by Kevin Chang on 2/5/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DecoderForm.h" resolved

#include "decoderform.h"
#include "ui_DecoderForm.h"
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <iostream>

DecoderForm::DecoderForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::DecoderForm) {
  ui->setupUi(this);

  auto layout = new QGridLayout(this);

  layout->addWidget(inputBoxLabel(), 0, 0);
  layout->addWidget(inputBox(), 1, 0);
}

DecoderForm::~DecoderForm() {
  delete ui;
}

auto DecoderForm::inputBoxLabel() -> QLabel * {
  auto inputBoxLabel = new QLabel(this);
  inputBoxLabel->setText("Input text");

  return inputBoxLabel;
}

auto DecoderForm::inputBox() -> QLineEdit * {
  auto inputBox = new QLineEdit(this);

  // Update this->inputText whenever the text box's contents change
  QObject::connect(inputBox,
                   &QLineEdit::textChanged,
                   [this, inputBox]() { inputText = inputBox->text().toStdString(); });

  return inputBox;
}
