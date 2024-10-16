#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1100, 630);

    // Inicialización del reproductor de medios y configuración de salida de audio
    Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    Player->setAudioOutput(audioOutput);

    // Creación del panel lateral (Dock) para la lista de archivos multimedia
    QDockWidget *dock = new QDockWidget(tr("Lista de Archivos"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // Lista de archivos que serán mostrados en el panel lateral
    QListWidget *fileList = new QListWidget(dock);
    fileList->addItem("El poder de tu visión.mp4");
    fileList->addItem("Las reglas del exito.mp4");
    fileList->addItem("Esclava (Remix).mp3");
    fileList->addItem("No Hay Nadie Más (Official Video).mp3");

    // Conectar selección de archivo a la reproducción correspondiente
    connect(fileList, &QListWidget::itemClicked, this, &MainWindow::onFileSelected);

    // Agregar la lista de archivos al panel lateral
    dock->setWidget(fileList);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    // Inicialización del reproductor y widget de video de fondo
    BackgroundPlayer = new QMediaPlayer(this);
    BackgroundVideo = new QVideoWidget(ui->groupBox_Video);
    BackgroundVideo->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
    BackgroundPlayer->setVideoOutput(BackgroundVideo);
    BackgroundVideo->setVisible(false);

    // Configuración para reproducción en bucle del video de fondo
    connect(BackgroundPlayer, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            BackgroundPlayer->play();
        }
    });

    // Asignación de iconos a los botones del reproductor
    ui->pushButton_Play_Pause->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/play.png"));
    ui->pushButton_Stop->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/stop.png"));
    ui->pushButton_Seek_Backward->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/retroceder.png"));
    ui->pushButton_Seek_Forward->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/avanzar.png"));
    ui->pushButton_Volume->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/sound.png"));

    // Configuración inicial de volumen
    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
    ui->horizontalSlider_Volume->setValue(30);
    audioOutput->setVolume(ui->horizontalSlider_Volume->value() / 100.0);

    // Conexión de las señales del reproductor para el manejo de duración y posición
    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    ui->horizontalSlider_Duration->setRange(0, Player->duration() / 1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Método que actualiza la duración máxima del video en el deslizador de progreso
void MainWindow::durationChanged(qint64 duration)
{
    mDuration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

// Método que actualiza la posición del video en el deslizador de progreso
void MainWindow::positionChanged(qint64 duration)
{
    if (!ui->horizontalSlider_Duration->isSliderDown())
    {
        ui->horizontalSlider_Duration->setValue(duration / 1000);
    }
    updateDuration(duration / 1000);
}

// Actualización del tiempo actual y total del video
void MainWindow::updateDuration(qint64 Duration)
{
    if (Duration || mDuration)
    {
        QTime CurrentTime((Duration / 3600) % 60, (Duration / 60) % 60, Duration % 60, (Duration * 1000) % 1000);
        QTime TotalTime((mDuration / 3600) % 60, (mDuration / 60) % 60, mDuration % 60, (mDuration * 1000) % 1000);
        QString Format = "";
        if (mDuration > 3600) Format = "hh:mm:ss";
        else Format = "mm:ss";

        ui->label_current_Time->setText(CurrentTime.toString(Format));
        ui->label_Total_Time->setText(TotalTime.toString(Format));
    }
}

// Método para abrir un archivo de video o audio desde el explorador
void MainWindow::on_actionOpen_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Seleccione Un video"), "", tr("MP4 Files (*.mp4);;MP3 Files (*.mp3)"));

    if (FileName.isEmpty()) {
        return;
    }

    if (FileName.endsWith(".mp3")) {
        // Reproducir archivo de audio y mostrar video de fondo
        BackgroundPlayer->setSource(QUrl::fromLocalFile("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/disco.mp4"));
        BackgroundVideo->setVisible(true);
        BackgroundPlayer->play();

        Player->setSource(QUrl::fromLocalFile(FileName));
        Player->play();
    } else {
        // Reproducción de un archivo de video
        BackgroundVideo->setVisible(false);
        Video = new QVideoWidget();
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setParent(ui->groupBox_Video);
        Player->setVideoOutput(Video);
        Player->setSource(QUrl::fromLocalFile(FileName));
        Video->setVisible(true);
        Video->show();
    }
}

// Controla el cambio de la posición del video con el deslizador
void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
    Player->setPosition(value * 1000);
}

// Control del botón de Play/Pause
void MainWindow::on_pushButton_Play_Pause_clicked()
{
    if (IS_Pause == true)
    {
        IS_Pause = false;
        Player->play();
        ui->pushButton_Play_Pause->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/pausa.png"));
    }
    else
    {
        IS_Pause = true;
        Player->pause();
        ui->pushButton_Play_Pause->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/play.png"));
    }
}

// Control del botón de Stop
void MainWindow::on_pushButton_Stop_clicked()
{
    Player->stop();
}

// Mute/unmute del volumen
void MainWindow::on_pushButton_Volume_clicked()
{
    if (IS_Muted == false)
    {
        IS_Muted = true;
        ui->pushButton_Volume->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/mute.png"));
        audioOutput->setMuted(true);
    }
    else
    {
        IS_Muted = false;
        ui->pushButton_Volume->setIcon(QIcon("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/sound.png"));
        audioOutput->setMuted(false);
    }
}

// Control del volumen
void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0);
}

// Avance en el video (seek forward)
void MainWindow::on_pushButton_Seek_Backward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() - 20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
}

// Retroceso en el video (seek backward)
void MainWindow::on_pushButton_Seek_Forward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() + 20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
}

// Manejo de la selección de un archivo desde la lista para su reproducción
void MainWindow::onFileSelected(QListWidgetItem *item)
{
    QString fileName = item->text();
    QString fullFileName;

    // Mapear nombre del archivo a la ruta completa del archivo en el sistema
    if (fileName == "El poder de tu visión.mp4") {
        fullFileName = "C:/Users/maria/Desktop/Proyecto final/Video/imagenes/El poder de tu visión.mp4";
    } else if (fileName == "Las reglas del exito.mp4") {
        fullFileName = "C:/Users/maria/Desktop/Proyecto final/Video/imagenes/Las reglas del exito.mp4";
    } else if (fileName == "Esclava (Remix).mp3") {
        fullFileName = "C:/Users/maria/Desktop/Proyecto final/Video/imagenes/Esclava (Remix).mp3";
    } else if (fileName == "No Hay Nadie Más (Official Video).mp3") {
        fullFileName = "C:/Users/maria/Desktop/Proyecto final/Video/imagenes/Sebastián Yatra - No Hay Nadie Más (Official Video).mp3";
    }

    // Reproducir el archivo según su tipo (audio/video)
    if (!fullFileName.isEmpty()) {
        if (fullFileName.endsWith(".mp4")) {
            BackgroundVideo->setVisible(false);
            Video = new QVideoWidget();
            Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
            Video->setParent(ui->groupBox_Video);
            Player->setVideoOutput(Video);
            Player->setSource(QUrl::fromLocalFile(fullFileName));
            Video->setVisible(true);
            Player->play();
        } else if (fullFileName.endsWith(".mp3")) {
            BackgroundPlayer->setSource(QUrl::fromLocalFile("C:/Users/maria/Desktop/Proyecto final/Video/imagenes/disco.mp4"));
            BackgroundVideo->setVisible(true);
            BackgroundPlayer->play();
            Player->setSource(QUrl::fromLocalFile(fullFileName));
            Player->play();
        }
    }
}
