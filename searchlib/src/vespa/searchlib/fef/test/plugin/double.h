// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include <string>
#include <vector>
#include <vespa/searchlib/fef/blueprint.h>
#include <vespa/searchlib/fef/featureexecutor.h>

namespace search {
namespace fef {
namespace test {

class DoubleExecutor : public FeatureExecutor
{
private:
    size_t _cnt;
public:
    DoubleExecutor(size_t cnt) : _cnt(cnt) {}
    virtual void execute(uint32_t docId);
};


class DoubleBlueprint : public Blueprint
{
private:
    size_t _cnt;
public:
    DoubleBlueprint();
    virtual void visitDumpFeatures(const IIndexEnvironment & indexEnv, IDumpFeatureVisitor & visitor) const;
    virtual Blueprint::UP createInstance() const { return Blueprint::UP(new DoubleBlueprint()); }
    virtual bool setup(const IIndexEnvironment & indexEnv, const StringVector & params);
    virtual FeatureExecutor &createExecutor(const IQueryEnvironment &queryEnv, vespalib::Stash &stash) const override;
};

} // namespace test
} // namespace fef
} // namespace search

