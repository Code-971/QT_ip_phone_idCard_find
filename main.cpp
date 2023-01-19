#include "widget.h"
#include <QApplication>
#include <QTranslator>
#include "QDebug"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "hello_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            QApplication::installTranslator(&translator);
            break;
        }
    }

    widget w;

    w.show();
//    std::cout << w.get_id_card_array()->toStdString() << std::endl;
//    std::cout << w.get_ip_array()->toStdString() << std::endl;

    return QApplication::exec();
}
