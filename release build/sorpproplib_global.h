#ifndef SORPPROPLIB_GLOBAL_H
#define SORPPROPLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SORPPROPLIB_LIBRARY)
#  define SORPPROPLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SORPPROPLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SORPPROPLIB_GLOBAL_H
