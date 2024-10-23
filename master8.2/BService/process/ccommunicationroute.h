#ifndef CCOMMUNICATIONROUTE_H
#define CCOMMUNICATIONROUTE_H

#include <QHash>
#include <QObject>
<<<<<<< HEAD
=======
#include <QTimer>
>>>>>>> 341c9929318cff5b207944113ce95e985e86616c
#include "struct.h"

#define INTERFACEBOARD_TIMEOUT 4000
#define INTERFACEBOARD_PORT_NUMBER_STR "_portNumber_"   // 0 ~ 4, 0 is the interface board
#define INTERFACEBOARD_PORT_SPEED_STR "_portSPeed_"
#define INTERFACEBOARD_COMPORT_NUMBER_STR "Port"        // 1 2 3 ...
#define INTERFACEBOARD_COMMPNYCODE "commpny"
#define INTERFACEBOARD_PANEL   "panel"

class CProcessBase;
class CCommunicationManager;

class CCommunicationRoute : public QObject
{
    Q_OBJECT
public:
    explicit CCommunicationRoute(QObject *parent = 0);
    ~CCommunicationRoute();
    bool createRoute(CProcessBase* process, const int type, const QHash<QString, QVariant>& control);
    void setLedStatus(const int ledStatus1, const int ledStatus2, const int ledStatus3);
<<<<<<< HEAD
//    void printData(const QByteArray& data);
//    void reset(bool binit = false);
//    void resetLed(bool binit);
=======
>>>>>>> 341c9929318cff5b207944113ce95e985e86616c
    void openCommunication();
    void closeCommunication();
    void setDebug(const bool enable);
    QString canNameByAdd(int canportAdd);
    void testLinkageCom();
    void setLinkageBaudRate(QString baudrateString);

    void canSendDataClear();
<<<<<<< HEAD
=======
    void canReceiveDataClear();
    void linkageSendData(QByteArray data);
>>>>>>> 341c9929318cff5b207944113ce95e985e86616c

private:
    void initCommunicationManager();
//    void initLineInfo();

    int  getIntFromByte(QByteArray data, int start, int len);
    QString createCommunication(const int type);
    QString getCommunicationName(const int type);
    int  getCommunicationType(const QString lineName);
    bool isCommunicationLine(const int type) const;
    bool communicationIsActive(const QString& name) const;

signals:
<<<<<<< HEAD
    void sendCommandData(const QString &lineName,/*��·����*/ const int &infotype,/*��������*/
                             const QHash<QString,QVariant> &controlDomain,/*������*/
                             const QByteArray &data/* �����*/);
//    void sendLedData(const QString &lineName, const int &infotype,
//                             const QByteArray &data);
//    void sendLinkageData(const QString &lineName, const int &infotype, const QByteArray &data);

=======
>>>>>>> 341c9929318cff5b207944113ce95e985e86616c
    void communicationSendEvent(const QString& name, const QString &commandName, const QHash<QString, QVariant>& control, const QByteArray &data);
    void processRecvEvent(const QString& processname, const int &infotype, const QHash<QString, QVariant>& control, const QByteArray &data);

public slots:
<<<<<<< HEAD
    void procProcessSendEvent(const QString &processname, const int &infoType,
                              const QHash<QString, QVariant>& control, const QByteArray &data);

    void procCommunicationRecvEvent(const QString &lineName,const int &infoType,
                                    const QHash<QString, QVariant> &controlDomain,
                                    const QByteArray &data);
private:
    CCommunicationManager*  m_communicationManager;
=======
    void procCommunicationRecvEvent(const QString &lineName,const int &infoType,
                                    const QHash<QString, QVariant> &controlDomain,
                                    const QByteArray &data);
    void slot_stopTestLinkageCom();
public:
    CCommunicationManager*  m_communicationManager;
private:

>>>>>>> 341c9929318cff5b207944113ce95e985e86616c
    CCommunicationManager*  m_printManager;
    QHash<int, int>         m_interfaceBoardPortSpeed;
    QHash<int, int>         m_currentLedStatus;
    QHash<QString, int>     m_interfaceInfo;
    QHash<QString, CProcessBase*>   m_process;
    QHash<QString, QString>         m_processCommunication;//<processname, linename>
    QList<QString>                  m_communication;/*line names list*/
    
};

#endif // CCOMMUNICATIONROUTE_H