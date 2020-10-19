//
// Created by Andrew on 19-Oct-20.
//

#ifndef ATM_DEPOSITCONDITIONS_H
#define ATM_DEPOSITCONDITIONS_H

#include <QtGui/qopengl.h>

typedef uint Month;
typedef double Interest;

class DepositConditions {
public:
	static const QHash<Month, Interest> depositingOptions;
};


#endif //ATM_DEPOSITCONDITIONS_H
