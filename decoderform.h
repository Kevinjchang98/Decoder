//
// Created by Kevin Chang on 2/5/2023.
//

#ifndef DECODER__DECODERFORM_H_
#define DECODER__DECODERFORM_H_

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class DecoderForm; }
QT_END_NAMESPACE

class DecoderForm : public QWidget {
 Q_OBJECT

 public:
  explicit DecoderForm(QWidget *parent = nullptr);
  ~DecoderForm() override;

 private:
  Ui::DecoderForm *ui;

  std::string inputText;

  auto inputBoxLabel() -> QLabel *;
  auto inputBox() -> QLineEdit *;

};

#endif //DECODER__DECODERFORM_H_
