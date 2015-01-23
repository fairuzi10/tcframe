#ifndef CPTEST_CONSTRAINT_H
#define CPTEST_CONSTRAINT_H

#include <functional>
#include <string>
#include <vector>

using std::function;
using std::string;
using std::vector;

namespace org { namespace iatoki { namespace cptest {

class Predicate {
private:
    function<bool()> callback;
    string description;

public:
    Predicate(function<bool()> callback, string description) {
        this->callback = callback;
        this->description = description;
    }

    function<bool()> getCallback() {
        return callback;
    }

    string getDescription() {
        return description;
    }
};

class Subtask {
private:
    vector<Predicate> predicates;

public:
    void addPredicate(Predicate predicate) {
        predicates.push_back(predicate);
    }

    vector<Predicate> getPredicates() {
        return predicates;
    }
};

}}}

#endif