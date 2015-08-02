var cpuid = require('bindings')('asm-cpuid');
module.exports = function() {
  return cpuid();
}
