//
// Created by Andrew on 19-Oct-20.
//

#ifndef ATM_CREDITCONDITIONS_H
#define ATM_CREDITCONDITIONS_H


#include <QtCore/QHash>

typedef uint Month;
typedef double Interest;

class CreditConditions {
public:
	static const QHash<Month, Interest> creditingOptions;
};


#endif //ATM_CREDITCONDITIONS_H
