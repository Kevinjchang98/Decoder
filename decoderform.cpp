//
// Created by Kevin Chang on 2/5/2023.
//

#include "decoderform.h"
#include "ui_DecoderForm.h"
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <iostream>

DecoderForm::DecoderForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::DecoderForm) {
  ui->setupUi(this);

  auto layout = new QGridLayout(this);

  layout->addWidget(inputBoxLabelPtr, 0, 0);
  layout->addWidget(inputBoxPtr, 1, 0);
  layout->addWidget(decryptButtonPtr, 2, 0);
  layout->addWidget(outputBoxPtr, 3, 0);
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

auto DecoderForm::decryptButton() -> QPushButton * {
  auto decryptButton = new QPushButton(this);
  decryptButton->setText("Decrypt");

  QObject::connect(decryptButton,
                   &QPushButton::pressed,
                   [this]() {
                     auto decryptedText = decryptCaesarShift(this->inputText);
                     outputBoxPtr->setText(
                         decryptedText.length() == 0 ? "Empty input" : QString::fromStdString(decryptedText));
                   });

  return decryptButton;
}

auto DecoderForm::outputBox() -> QLabel * {
  auto outputBox = new QLabel(this);
  outputBox->setText("Enter some text in the input box and click decrypt");

  return outputBox;
}

auto DecoderForm::decryptCaesarShift(std::string text) -> std::string {
  // TODO: Finish
  return text;
}
