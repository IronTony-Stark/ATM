//
// Created by Andrew on 19-Oct-20.
//

#include <QtCore/QHash>
#include "DepositConditions.h"

const QHash<Month, Interest> DepositConditions::depositingOptions = {{6,  0.08},
																	 {8,  0.10},
																	 {12, 0.14}};