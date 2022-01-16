// Copyright (c) 2011-2020 The DRiyal Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DRIYAL_QT_DRIYALADDRESSVALIDATOR_H
#define DRIYAL_QT_DRIYALADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class DRiyalAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DRiyalAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** DRiyal address widget validator, checks for a valid driyal address.
 */
class DRiyalAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit DRiyalAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // DRIYAL_QT_DRIYALADDRESSVALIDATOR_H
