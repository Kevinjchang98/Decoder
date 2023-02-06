//
// Created by Kevin Chang on 2/5/2023.
//

#include "../include/decoderform.h"
#include "ui_DecoderForm.h"
#include "../include/Decoder.h"
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

DecoderForm::DecoderForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::DecoderForm) {
  ui->setupUi(this);

  auto layout = new QGridLayout(this);

  // Input box label
  layout->addWidget(inputBoxLabelPtr, 0, 0);
  layout->setRowMinimumHeight(0, 30);

  // Input textbox
  layout->addWidget(inputBoxPtr, 1, 0);
  layout->setRowStretch(1, 1);

  // Decrypt button
  layout->addWidget(decryptButtonPtr, 2, 0);

  // Empty spacer
  layout->setRowStretch(3, 1);

  // Output box label
  layout->addWidget(outputBoxLabelPtr, 4, 0);
  layout->setRowMinimumHeight(4, 30);

  // Output text display
  layout->addWidget(outputBoxPtr, 5, 0);
  layout->setRowStretch(5, 1);
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

  // Pressing enter is the same as pressing the decrypt button
  QObject::connect(inputBox, &QLineEdit::returnPressed, [=]() { decryptButtonPtr->click(); });

  return inputBox;
}

auto DecoderForm::decryptButton() -> QPushButton * {
  auto decryptButton = new QPushButton(this);
  decryptButton->setText("Decrypt");

  QObject::connect(decryptButton,
                   &QPushButton::pressed,
                   [this]() {
                     auto decryptedText = Decoder::decryptCaesarShift(this->inputText);
                     outputBoxPtr->setText(
                         decryptedText.length() == 0 ? "Empty input" : QString::fromStdString(decryptedText));
                   });

  return decryptButton;
}

auto DecoderForm::outputBoxLabel() -> QLabel * {
  auto outputBoxLabel = new QLabel(this);
  outputBoxLabel->setText("Decrypted result");

  return outputBoxLabel;
}

auto DecoderForm::outputBox() -> QLabel * {
  auto outputBox = new QLabel(this);
  outputBox->setText("Enter some text in the input box and click decrypt");

  return outputBox;
}

