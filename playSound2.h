#pragma once

#include <QtWidgets/QWidget>
#include "ui_playSound2.h"
#include<qaudioinput.h>
#include<qaudiooutput.h>
#include<Windows.h>
#include<qiodevice.h>
#include<iostream>
#include<qfile.h>

class playSound2 : public QWidget
{
    Q_OBJECT

public:
    playSound2(QWidget *parent = Q_NULLPTR);
    ~playSound2();

private:
    Ui::playSound2Class *ui;

    QAudioInput* audio_in;
    QAudioInput* audio_in2;
    QAudioOutput* audio_out;

    QFile destinationFile;
};
