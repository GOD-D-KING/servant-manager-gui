#ifndef TEMPORARYCOMMANDSFORQML_H
#define TEMPORARYCOMMANDSFORQML_H

#include <QObject>

class TemporaryCommandsForQml : public QObject
{
    Q_OBJECT
public:
    explicit TemporaryCommandsForQml(QObject *parent = 0);
    Q_INVOKABLE void runHardwareAssessment();
    Q_INVOKABLE void runDownloader(int itemIndex);
    Q_INVOKABLE void runInstaller(int itemIndex);
    Q_INVOKABLE void bootServer(int itemIndex);
    Q_INVOKABLE void shutdownServer();
    Q_INVOKABLE void updateServerControlUI(const QString &machineName);
    Q_INVOKABLE void deleteServer(const QString &machineName);
signals:

public slots:

};

#endif // TEMPORARYCOMMANDSFORQML_H
