#include <QCoreApplication>

#include "sorpproplib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SorpPropLib sLib;
    sLib.Test();

    return a.exec();
}
