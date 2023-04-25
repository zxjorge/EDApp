#include "flagconstants.h"

QString extractCountryCode(const QString &name) {
    return name.sliced(name.length() - 6, 2);
}
