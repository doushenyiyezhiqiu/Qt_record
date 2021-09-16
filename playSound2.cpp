#include "playSound2.h"

struct WAVHEADER
{
    // RIFF 头
    char RiffName[4];
    unsigned long nRiffLength;
    // 数据类型标识符
    char WavName[4];
    // 格式块中的块头
    char FmtName[4];
    unsigned long nFmtLength;
    // 格式块中的块数据
    unsigned short nAudioFormat;
    unsigned short nChannleNumber;
    unsigned long nSampleRate;
    unsigned long nBytesPerSecond;
    unsigned short nBytesPerSample;
    unsigned short nBitsPerSample;
    // 数据块中的块头
    char    DATANAME[4];
    unsigned long   nDataLength;
};

playSound2::playSound2(QWidget *parent)
    : QWidget(parent)
{
    ui->setupUi(this);

    destinationFile.setFileName("test.wav");
    destinationFile.open(QIODevice::WriteOnly | QIODevice::Truncate);

    //AllocConsole();
    //freopen("CONIN$", "r+t", stdin); // 重定向 STDIN
    //freopen("CONOUT$", "w+t", stdout); // 重定向STDOUT

    QAudioFormat format;
    // set up the format you want, eg.
    format.setSampleRate(16000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        std::cout << "default format not supported try to use nearest"<<std::endl;
        format = info.nearestFormat(format);
    }

    audio_in = new QAudioInput(format, this);
    //bufDevice->open(QIODevice::ReadWrite | QIODevice::Truncate);
    audio_in2 = new QAudioInput(format, this);
    audio_out = new QAudioOutput(format, this);

    connect(ui->btn_start, &QPushButton::clicked, [=]() {
        //audio_in->start(bufDevice);
        //bufDevice = audio_in->start();
        QIODevice* myDevice = audio_in->start();
        audio_in2->start(&destinationFile);

        audio_out->start(myDevice);
        });

    connect(ui->btn_stop, &QPushButton::clicked, [=]() {
        audio_in->stop();
        audio_out->stop();
        audio_in2->stop();

        QIODevice* device{ nullptr };
        device = &destinationFile;

        static WAVHEADER wavHeader;
        qstrcpy(wavHeader.RiffName, "RIFF");
        qstrcpy(wavHeader.WavName, "WAVE");
        qstrcpy(wavHeader.FmtName, "fmt ");
        qstrcpy(wavHeader.DATANAME, "data");
        wavHeader.nFmtLength = 16;
        int nAudioFormat = 1;
        wavHeader.nAudioFormat = nAudioFormat;
        wavHeader.nBitsPerSample = 16;
        wavHeader.nChannleNumber = 1;
        wavHeader.nSampleRate = 16000;
        wavHeader.nBytesPerSample = wavHeader.nChannleNumber * wavHeader.nBitsPerSample / 8;
        wavHeader.nBytesPerSecond = wavHeader.nSampleRate * wavHeader.nChannleNumber * wavHeader.nBitsPerSample / 8;
        wavHeader.nRiffLength = device->size() - 8 + sizeof(WAVHEADER);
        wavHeader.nDataLength = device->size();
        //写到IO设备头
        device->seek(0);
        device->write(reinterpret_cast<char*>(&wavHeader), sizeof WAVHEADER);

        destinationFile.close();
        delete audio_in;
        delete audio_out;
        delete audio_in2;
        });
}

playSound2::~playSound2()
{
    delete ui;
    //delete audio_in;
    //delete audio_out;
    //delete audio_in2;
    //delete destinationFile;
}
