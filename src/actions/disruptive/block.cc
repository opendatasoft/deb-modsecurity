/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "src/actions/disruptive/block.h"

#include <iostream>
#include <string>
#include <memory>

#include "modsecurity/transaction.h"
#include "modsecurity/rule.h"
#include "modsecurity/rules.h"
#include "modsecurity/intervention.h"
#include "src/actions/data/status.h"

namespace modsecurity {
namespace actions {
namespace disruptive {


bool Block::evaluate(Rule *rule, Transaction *transaction,
    std::shared_ptr<RuleMessage> rm) {
#ifndef NO_LOGS
    transaction->debug(8, "Marking request as disruptive.");
#endif

    for (Action *a : transaction->m_rules->m_defaultActions[rule->m_phase]) {
        if (a->isDisruptive() == false
            || dynamic_cast<actions::disruptive::Block *>(a) != NULL) {
            continue;
        }
        a->evaluate(rule, transaction, rm);
    }

    return true;
}


}  // namespace disruptive
}  // namespace actions
}  // namespace modsecurity
