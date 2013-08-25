{
    "targets": [{
        "target_name"  : "max31855pi"
      , "include_dirs" : [
            "<!(node -p -e \"require('path').dirname(require.resolve('nan'))\")"
        ]
      , "cflags_cc"      : [
            "-fexceptions"
        ]
      , "cflags"       : [
            "-fexceptions"
          , "-Wno-unused-variable"
        ]
      , "sources"      : [
            "src/bcm2835.c"
          , "src/max31855.cc"
          , "src/node_max31855.cc"
        ]
    }]
}
