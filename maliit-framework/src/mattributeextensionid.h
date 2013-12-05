/* * This file is part of Maliit framework *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * Contact: maliit-discuss@lists.maliit.org
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */


#ifndef MATTRIBUTEEXTENSIONID_H
#define MATTRIBUTEEXTENSIONID_H

#include <QObject>
#include <QHash>
#include <QPointer>

//! \internal
/*! \ingroup maliitserver
 * \brief Contains global unique identifier for an attribute extension.
 *
 * Such identifiers are generated by MAttributeExtensionManager::generateId.
 */
class MAttributeExtensionId
{
public:
    //! Construct invalid identifier.
    MAttributeExtensionId();

    //! Construct identifier with given application \a id and \a service name.
    MAttributeExtensionId(int id, const QString &service);

    //! Return identifier for standard attribute extension
    static MAttributeExtensionId standardAttributeExtensionId();

    //! Return true if identifier is valid.
    bool isValid() const;

    //! Returns true if \a other is equal to this object
    bool operator==(const MAttributeExtensionId &other) const;

    //! Returns true if \a other is not equal to this object
    bool operator!=(const MAttributeExtensionId &other) const;

    //! \return service part of the ID, given to constructor
    QString service() const;

    //! Id given by application
    int id() const;

private:
    //! Id given by application
    int m_id;

    //! Unique application identifier
    QString m_service;

    friend uint qHash(const MAttributeExtensionId &id);
};

//! Returns hash value for given \a id
uint qHash(const MAttributeExtensionId &id);

//! \internal_end

#endif
