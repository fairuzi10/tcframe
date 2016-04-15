#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

#include "tcframe/experimental/constraint/Constraint.hpp"

using std::map;
using std::set;
using std::string;
using std::vector;

namespace tcframe { namespace experimental {

struct ConstraintSuiteVerificationResult {
private:
    map<int, vector<string>> unsatisfiedConstraintDescriptionsByConstraintGroupId_;
    set<int> satisfiedButNotAssignedConstraintGroupIds_;

public:
    ConstraintSuiteVerificationResult(
            map<int, vector<string>> unsatisfiedConstraintDescriptionsByConstraintGroupId,
            set<int> satisfiedButNotAssignedConstraintGroupIds)
            : unsatisfiedConstraintDescriptionsByConstraintGroupId_(unsatisfiedConstraintDescriptionsByConstraintGroupId)
            , satisfiedButNotAssignedConstraintGroupIds_(satisfiedButNotAssignedConstraintGroupIds)
    {}

    bool isValid() const {
        return unsatisfiedConstraintDescriptionsByConstraintGroupId_.empty() &&
               satisfiedButNotAssignedConstraintGroupIds_.empty();
    }

    const map<int, vector<string>>& unsatisfiedConstraintDescriptionsByConstraintGroupId() const {
        return unsatisfiedConstraintDescriptionsByConstraintGroupId_;
    }

    const set<int>& satisfiedButNotAssignedConstraintGroupIds() const {
        return satisfiedButNotAssignedConstraintGroupIds_;
    }
};

}}
