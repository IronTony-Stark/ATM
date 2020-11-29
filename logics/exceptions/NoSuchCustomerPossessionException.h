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
	NoSuchCustomerPossessionException(QString customerId, QString possessionId, QString possName);

	[[nodiscard]] const QString& possessionType() const;

	[[nodiscard]] const QString& customerId() const;

	[[nodiscard]] const QString& possessionId() const;

	const char* what() const noexcept override;

    ~NoSuchCustomerPossessionException() override = default;

private:
	const QString _possName;
	const QString _customerId;
	const QString _possessionId;
};

std::ostream& operator<<(std::ostream&, const NoSuchCustomerPossessionException&);

#endif //ATM_NOSUCHCUSTOMERPOSSESSIONEXCEPTION_H
