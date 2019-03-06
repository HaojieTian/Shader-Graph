#include "Window.h"

#include <vector>
#include <memory>
#include <string>

#include <QComboBox>
#include <QSurfaceFormat>

#include <core/Core.h>

#include "ui_Window.h"

#define FORMAT_VERSION 4, 1
#define FORMAT_DEPTH_BUFFER_SIZE 24

Window::Window(QWidget * Parent) :
    QMainWindow(Parent),
    ui(new Ui::Window)
{
    // Step 0 : Initialise the default format
    QSurfaceFormat format;
    format.setVersion(FORMAT_VERSION);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setDepthBufferSize(FORMAT_DEPTH_BUFFER_SIZE);
    QSurfaceFormat::setDefaultFormat(format);

    // Step 1 : Setup the user interface
    ui->setupUi(this);
    setCentralWidget(ui->widget);

    // Step 2 : Setup the logger
    LOG_INIT("../data/ShaderGraph.log", ui->logPanel);
    LOG_CONNECT(ui->logLevelSelector);

    // Step 3 : Update the GL-Widget
    // FIXME : for some reason, a simple ui->preview->update doesn't "work".
    //         It needs a bit a delay to display the build scene.
    QTimer::singleShot(10, ui->preview, SLOT(update()));
    ;
}

Window::~Window()
{
    LOG_DESTROY; // Destroy the log system.
    delete ui;
}