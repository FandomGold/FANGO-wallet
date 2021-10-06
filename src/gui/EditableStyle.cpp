// Copyright (c) 2021 Conceal Network & Conceal Devs
//
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "EditableStyle.h"

#include <QApplication>
#include <QFontDatabase>

#include "Settings.h"

namespace WalletGui
{
  EditableStyle::~EditableStyle()
  {
    widgets.clear();
    buttons.clear();
    labels.clear();
  }

  int EditableStyle::setStyles(int change)
  {
    /** Set the base font sizes */
    baseFontSize = change;
    baseTitleSize = change + 7;
    baseSmallButtonSize = change - 3;
    baseLargeButtonSize = change - 1;

    int id = -2;

    QString fontName = Settings::instance().getFont();
    if (fontName == "orbitron")
    {
      id = QFontDatabase::addApplicationFont(":/fonts/orbitron.ttf");
    }
    else if (fontName == "cinzel")
    {
      id = QFontDatabase::addApplicationFont(":/fonts/Cinzel-Regular.ttf");
    }
    else if (fontName == "Lato")
    {
      id = QFontDatabase::addApplicationFont(":/fonts/Lato-Regular.ttf");
    }
    else
    {
      id = QFontDatabase::addApplicationFont(":/fonts/GothamBook.ttf");
    }

    currentFont.setFamily(fontName);
    currentFont.setPixelSize(baseFontSize);
    currentFont.setLetterSpacing(QFont::PercentageSpacing, 102);
    currentFont.setHintingPreference(QFont::PreferFullHinting);
    currentFont.setStyleStrategy(QFont::PreferAntialias);

    smallButtonFont.setFamily(fontName);
    smallButtonFont.setLetterSpacing(QFont::PercentageSpacing, 102);
    smallButtonFont.setPixelSize(baseSmallButtonSize);
    smallButtonFont.setHintingPreference(QFont::PreferFullHinting);
    smallButtonFont.setStyleStrategy(QFont::PreferAntialias);

    largeButtonFont.setFamily(fontName);
    largeButtonFont.setLetterSpacing(QFont::PercentageSpacing, 102);
    largeButtonFont.setPixelSize(baseLargeButtonSize);
    largeButtonFont.setHintingPreference(QFont::PreferFullHinting);
    largeButtonFont.setStyleStrategy(QFont::PreferAntialias);

    titleFont.setFamily(fontName);
    titleFont.setLetterSpacing(QFont::PercentageSpacing, 102);
    titleFont.setPixelSize(baseTitleSize);
    titleFont.setHintingPreference(QFont::PreferFullHinting);
    titleFont.setStyleStrategy(QFont::PreferAntialias);

    /* Create our common pool of styles */
    tableStyle = QString(
                     "QHeaderView::section"
                     "{"
                     "font-size: %1 px;"
                     "background-color: black;"
                     "color: #ddd;"
                     "font-weight: bold;"
                     "height: 37px;"
                     "border: 1px solid #444;"
                     "padding-left: .5em;"
                     "}"
                     "QTreeView::item"
                     "{"
                     "color: #bbb;"
                     "height: 37px;"
                     "outline: none;"
                     "}"
                     "QTreeView::item:selected"
                     "{"
                     "background-color: #ffcb00;"
                     "color: black;"
                     "}"
                     "QTreeView"
                     "{"
                     "alternate-background-color: #080808;"
                     "background: black"
                     "}")
                     .arg(baseFontSize);
    b1Style = QString(
                  "QPushButton"
                  "{"
                  "font-size: %1 px;"
                  "color:#ddd;"
                  "border:1px solid #ffcb00;"
                  "border-radius:5px;"
                  "padding: 5px;"
                  "}"
                  "QPushButton:hover"
                  "{"
                  "color: black;"
                  "background-color: #ffcb00;"
                  "}")
                  .arg(baseLargeButtonSize);
    b2Style = QString(
                  "QPushButton"
                  "{"
                  "font-size: %1 px;"
                  "color: #ffcb00;"
                  "border:1px solid #ffcb00;"
                  "border-radius: 5px"
                  "}"
                  "QPushButton:hover"
                  "{"
                  "color:#ffcb00;"
                  "}")
                  .arg(baseSmallButtonSize);
    fontStyle = QString("font-size: %1 px;").arg(baseFontSize);
    darkFontStyle = QString("font-size: %1 px; color: #888;").arg(baseFontSize);
    orangeFontStyle = QString("font-size: %1 px; color: #ffcb00;").arg(baseFontSize);

    widgets = getWidgets();
    foreach (QWidget *widget, widgets)
    {
      widget->setFont(currentFont);
    }

    buttons = getButtons();
    foreach (QPushButton *button, buttons)
    {
      /* Set the font and styling for b1 styled buttons */
      if (button->objectName().contains("b1_"))
      {
        button->setStyleSheet(b1Style);
        button->setFont(largeButtonFont);
        button->setMinimumHeight(30);
      }

      /* Set the font and styling for b2 styled buttons */
      if (button->objectName().contains("b2_"))
      {
        button->setStyleSheet(b2Style);
        button->setFont(smallButtonFont);
      }

      /* Set the font and styling for lm styled buttons */
      if (button->objectName().contains("lm_"))
      {
        button->setFont(currentFont);
      }

      /* Set the font and styling for sm styled buttons */
      if (button->objectName().contains("sm_"))
      {
        button->setFont(currentFont);
      }

      /* Set the font and styling for m styled buttons */
      if (button->objectName().contains("m_"))
      {
        button->setFont(currentFont);
      }
    }

    labels = getLabels();
    foreach (QLabel *label, labels)
    {
      if (label->objectName().contains("title_"))
      {
        label->setFont(titleFont);
      }
      else if (label->objectName().contains("o_"))
      {
        label->setStyleSheet(orangeFontStyle);
      }
      else
      {
        label->setFont(currentFont);
      }
    }

    applyStyles();
    return id;
  }

  QList<QWidget *> EditableStyle::getWidgets() { return QList<QWidget *>(); }

  QList<QPushButton *> EditableStyle::getButtons() { return QList<QPushButton *>(); }

  QList<QLabel *> EditableStyle::getLabels() { return QList<QLabel *>(); }

  void EditableStyle::applyStyles() { }
}  // namespace WalletGui
