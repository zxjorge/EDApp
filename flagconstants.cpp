/**
 * FlagConstants.cpp made by Najmingle for A8-An-Educational-App - CS 3505 Spring 2023
 * This cpp file is used to get the country code to be able to make the unordered_map present in flagConstants.h
 * Reviewed by: Najman Husaini
 */
#include "flagconstants.h"

QString extractCountryCode(const QString &name) {
    return name.sliced(name.length() - 6, 2);
}
