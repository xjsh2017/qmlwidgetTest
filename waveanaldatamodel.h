#ifndef WAVEANALDATAMODEL_H
#define WAVEANALDATAMODEL_H

#include <QDate>
#include <QObject>

class WaveAnalDataModel : public QObject
{
    Q_OBJECT
    QString m_test;

    Q_PROPERTY(QString test READ test WRITE setTest NOTIFY testChanged)

public:
    explicit WaveAnalDataModel(QObject *parent = 0);

    QString test() const
    {
        return m_test;
    }

signals:
    void testChanged(QString arg);

public slots:
    void setTest(QString arg)
    {
        if (m_test != arg) {
            m_test = arg;
            emit testChanged(arg);
        }
    }

};

#endif // WAVEANALDATAMODEL_H
