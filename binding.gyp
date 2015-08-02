{
  "targets": [
    {
      "target_name": "asm-cpuid",
      "sources": [ "asm-cpuid.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
