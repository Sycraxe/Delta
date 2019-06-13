#include "command.h"
#include <drivers/board.h>
#include <drivers/external_flash.h>
#include <drivers/power.h>
#include <drivers/wakeup.h>

namespace Ion {
namespace Device {
namespace Bench {
namespace Command {

void Sleep(const char * input) {
  if (input != nullptr) {
    reply(sSyntaxError);
    return;
  }
  reply(sOK);
  Device::Power::sleepConfiguration();
  Device::Board::shutdownPeripherals();
  Device::WakeUp::onUSBPlugging();
  Device::Power::internal_flash_suspend();
  Device::Board::setStandardFrequency(Device::Board::Frequency::High);
  Device::Board::initPeripherals(false);
}

}
}
}
}
