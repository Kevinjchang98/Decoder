//
// Created by Kevin Chang on 2/5/2023.
//

#ifndef DECODER__DECODERFORM_H_
#define DECODER__DECODERFORM_H_

#include <QWidget>
#include <QLabel>

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
  auto inputBox() -> QLabel *;

  static constexpr int margin = 10;
};

#endif //DECODER__DECODERFORM_H_
