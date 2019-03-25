#ifndef _WalletModel_H_
#define _WalletModel_H_

#include <QAbstractListModel>
#include <QStringList>
#include <QDate>
#include "HistoryModel.h"

class OrphicClaim
{
public:
    OrphicClaim(){;}
    OrphicClaim(const QString &type, const QString &name, const QString &make, const QString &model, const QString &year, const QString &serial, const QString &other, const QString &description, const QString &picture );

    QString type() const;
    QString name() const;
    QString make() const;
    QString model() const;
    QString year() const;
    QString serial() const;
    QString other() const;
    QString description() const;
    QString picture() const;

    void addHistory(QDate p_date, QString p_id, QString p_docHash);
    QList<HistoryItem> m_historyList;

private:
    QString m_type;
    QString m_name;
    QString m_make;
    QString m_model;
    QString m_year;
    QString m_serial;
    QString m_other;
    QString m_description;
    QString m_picture;

};

class OrphicWalletModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        NameRole,
        MakeRole,
        ModelRole,
        YearRole,
        SerialRole,
        OtherRole,
        DescriptionRole,
        PictureRole
    };

    OrphicWalletModel(QObject *parent = 0);

    void loadTempWallet();

    void addClaim(const OrphicClaim &animal);
    void addClaim(QString p_type, QString p_name, QString p_make, QString p_model, QString p_year, QString p_serial, QString p_other, QString p_desc, QString p_file);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void clearModel();

protected:
    QHash<int, QByteArray> roleNames() const;
public:
    QList<OrphicClaim> m_claimList;

    QString m_walletName;

};


#endif
