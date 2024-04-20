/*!
 * SPDX-FileCopyrightText: (C) 2023-2024 Matthias Fehring <https://www.huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef C_FORMS_NAMEDLISTPROPERTY_P_H
#define C_FORMS_NAMEDLISTPROPERTY_P_H

#include "logging_p.h"

#include <QList>
#include <QMap>
#include <QString>
#include <QQmlListProperty>

template<typename T, typename P>
class NamedListProperty
{
public:
    explicit NamedListProperty(P *p) : m_parent{p} {}
    ~NamedListProperty() = default;

    void append(T *item)
    {
        item->setParent(m_parent);
        m_list.push_back(item);
        if (!item->name().isEmpty()) {
            if (m_nameMap.contains(item->name())) {
//                qCWarning(C_FORMS) << *m_parent << "already contains a" << *item << " with this name - appending it anyway. Note that this will overwrite the item with the same name in the nameMap!";
            }
            m_nameMap.insert(item->name(), item);
        }
        if (!item->htmlId().isEmpty()) {
            if (m_idMap.contains(item->htmlId())) {
//                qCWarning(C_FORMS) << *m_parent << "already contains a" << *item << " with this HTML id - appending it anyway. Note that this will overwrite the item with the same HTML id in the idMap!";
            }
            m_idMap.insert(item->htmlId(), item);
        }
    }

    typename QList<T *>::size_type count() const noexcept
    {
        return m_list.count();
    }

    T *item(typename QList<T *>::size_type idx) const
    {
        if (idx >= 0 && idx < m_list.size()) {
            return m_list.at(idx);
        } else {
            return nullptr;
        }
    }

    T *itemByName(const QString &name) const
    {
        return m_nameMap.value(name, nullptr);
    }

    T *itemById(const QString &id) const
    {
        return m_idMap.value(id, nullptr);
    }

    void clear()
    {
        m_list.clear();
        m_nameMap.clear();
        m_idMap.clear();
    }

    void replace(typename QList<T *>::size_type idx, T *i)
    {
        T *current = item(idx);
        if (current) {
            if (!current->name().isEmpty()) {
                m_nameMap.remove(current->name());
            }
            if (!current->htmlId().isEmpty()) {
                m_idMap.remove(current->htmlId());
            }
        }
        i->setParent(m_parent);
        m_list[idx] = i;
        if (!i->name().isEmpty()) {
            if (m_nameMap.contains(i->name())) {
//                qCWarning(C_FORMS) << *m_parent << "already contains a" << *i << " with this name - replacing it anyway. Note that this will overwrite the item with the same name in the nameMap!";
            }
            m_nameMap.insert(i->name(), i);
        }
        if (!i->htmlId().isEmpty()) {
            if (m_idMap.contains(i->htmlId())) {
//                qCWarning(C_FORMS) << *m_parent << "already contains a" << *i << " with this HTML id - replacing it anyway. Note that this will overwrite the item with the same HTML id in the idMap!";
            }
            m_idMap.insert(i->htmlId(), i);
        }
    }

    void removeLast()
    {
        if (m_list.empty()) {
            return;
        }
        T *last = m_list.takeLast();
        if (!last->name().isEmpty()) {
            m_nameMap.remove(last->name());
        }
        if (!last->htmlId().isEmpty()) {
            m_idMap.remove(last->htmlId());
        }
    }

    QList<T *> list() const noexcept
    {
        return m_list;
    }

    QMap<QString, T *> nameMap() const noexcept
    {
        return m_nameMap;
    }

    QMap<QString, T *> idMap() const noexcept
    {
        return m_idMap;
    }

    bool isEmpty() const noexcept
    {
        return m_list.isEmpty();
    }

private:
    P *m_parent{nullptr};
    QList<T *> m_list;
    QMap<QString, T *> m_nameMap;
    QMap<QString, T *> m_idMap;

    Q_DISABLE_COPY(NamedListProperty);
};

#define C_FORMS_QMLLIST_FUNCS(type, typeLow, parentType) \
    static void append##type(QQmlListProperty<type> *list, type *item) \
    { \
        auto p = qobject_cast<parentType *>(list->object); \
        if (p) { \
            p->append##type(item); \
        } \
    } \
    \
    static QList<type *>::size_type typeLow##Count(QQmlListProperty<type> *list) \
    { \
        auto p = qobject_cast<parentType *>(list->object); \
        if (p) { \
            return p->typeLow##Count(); \
        } else {\
            return 0; \
        } \
    } \
    \
    static type * typeLow(QQmlListProperty<type> *list, QList<type *>::size_type idx) \
    { \
        auto p = qobject_cast<parentType *>(list->object); \
        if (p) { \
            return p->typeLow(idx); \
        } else {\
            return nullptr; \
        } \
    } \
    \
    static void clear##type##s(QQmlListProperty<type> *list) \
    { \
        auto p = qobject_cast<parentType *>(list->object); \
        if (p) { \
            p->clear##type##s(); \
        } \
    } \
    \
    static void replace##type(QQmlListProperty<type> *list, QList<type *>::size_type idx, type *item) \
    { \
        auto p = qobject_cast<parentType *>(list->object); \
        if (p) { \
            p->replace##type(idx, item); \
        } \
    } \
    \
    static void removeLast##type(QQmlListProperty<type> *list) \
    { \
        auto p = qobject_cast<parentType *>(list->object); \
        if (p) { \
            p->removeLast##type(); \
        } \
    }

#endif // C_FORMS_NAMEDLISTPROPERTY_P_H
