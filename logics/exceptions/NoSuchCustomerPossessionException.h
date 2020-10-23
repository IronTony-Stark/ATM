//
// Created by Andrew on 02-Oct-20.
//

#ifndef ATM_NOSUCHCUSTOMERPOSSESSIONEXCEPTION_H
#define ATM_NOSUCHCUSTOMERPOSSESSIONEXCEPTION_H


#include <exception>
#include <QtGui/qopengl.h>
#include <QtCore/QString>

class NoSuchCustomerPossessionException : std::exception {
public:
	NoSuchCustomerPossessionException(QString customerId, uint possessionId, QString possName);

	[[nodiscard]] const QString& possessionType() const;

	[[nodiscard]] QString customerId() const;

	[[nodiscard]] uint possessionId() const;

private:
	const QString _possName;
	const QString _customerId;
	const uint _possessionId;
};

std::ostream& operator<<(std::ostream&, const NoSuchCustomerPossessionException&);

#endif //ATM_NOSUCHCUSTOMERPOSSESSIONEXCEPTION_H
