// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include <string>
#include <vector>
#include <vespa/searchlib/fef/blueprint.h>
#include <vespa/searchlib/fef/featureexecutor.h>

namespace search {
namespace fef {
namespace test {

class SumExecutor : public FeatureExecutor
{
public:
    virtual bool isPure() { return true; }
    virtual void execute(uint32_t docId);
};


class SumBlueprint : public Blueprint
{
public:
    SumBlueprint();
    virtual void visitDumpFeatures(const IIndexEnvironment & indexEnv, IDumpFeatureVisitor & visitor) const;
    virtual Blueprint::UP createInstance() const { return Blueprint::UP(new SumBlueprint()); }
    virtual bool setup(const IIndexEnvironment & indexEnv, const StringVector & params);
    virtual FeatureExecutor &createExecutor(const IQueryEnvironment & queryEnv, vespalib::Stash &stash) const override;
};

} // namespace test
} // namespace fef
} // namespace search

