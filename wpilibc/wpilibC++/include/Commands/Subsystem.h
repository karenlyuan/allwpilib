/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.
 */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __SUBSYSTEM_H__
#define __SUBSYSTEM_H__

#include "ErrorBase.h"
#include "SmartDashboard/NamedSendable.h"
#include <string>

class Command;

class Subsystem : public ErrorBase, public NamedSendable {
  friend class Scheduler;

 public:
  Subsystem(const char *name);
  virtual ~Subsystem() = default;

  void SetDefaultCommand(Command *command);
  Command *GetDefaultCommand();
  void SetCurrentCommand(Command *command);
  Command *GetCurrentCommand() const;
  virtual void InitDefaultCommand();

 private:
  void ConfirmCommand();

  Command *m_currentCommand = nullptr;
  bool m_currentCommandChanged = true;
  Command *m_defaultCommand = nullptr;
  std::string m_name;
  bool m_initializedDefaultCommand = false;

 public:
  virtual std::string GetName();
  virtual void InitTable(ITable *table);
  virtual ITable *GetTable() const;
  virtual std::string GetSmartDashboardType() const;

 protected:
  ITable *m_table = nullptr;
};

#endif
