#pragma once


#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

class UpdateLogicalOperator : public LogicalOperator
{
public:
  UpdateLogicalOperator(Table *table, Value* value);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }

  Table *table() const { return table_; }
  const Value *values() const { return value_; }
  Value *values() { return value_; }

private:
  Table *table_ = nullptr;
  Value* value_;
};