//
// Created by Andrew on 19-Oct-20.
//

#include "CreditConditions.h"

const QHash<Month, Interest> CreditConditions::creditingOptions = {{6,  0.25},
																   {8,  0.24},
																   {12, 0.21}};
