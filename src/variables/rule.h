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

#include <string>
#include <vector>
#include <list>

#ifndef SRC_VARIABLES_RULE_H_
#define SRC_VARIABLES_RULE_H_

#include "src/variables/variable.h"

namespace modsecurity {

class Transaction;
namespace Variables {

class Rule_DictElement : public Variable {
 public:
    explicit Rule_DictElement(std::string dictElement)
        : Variable("RULE" + std::string(":") +
            std::string(dictElement)),
        m_dictElement(dictElement) { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) override {
        transaction->m_variableRule.resolve(m_dictElement, l);
    }

    std::string m_dictElement;
};


class Rule_NoDictElement : public Variable {
 public:
    Rule_NoDictElement()
        : Variable("RULE") { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) override {
        transaction->m_variableRule.resolve(l);
    }
};


class Rule_DictElementRegexp : public Variable {
 public:
    explicit Rule_DictElementRegexp(std::string dictElement)
        : Variable("RULE"),
        m_r(dictElement) { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) override {
        transaction->m_variableRule.resolveRegularExpression(
            &m_r, l);
    }

    Utils::Regex m_r;
};

}  // namespace Variables
}  // namespace modsecurity

#endif  // SRC_VARIABLES_RULE_H_
