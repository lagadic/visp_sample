# visp_sample

ViSP sample code used as code snippet in ViSP doxygen [documentation](https://visp-doc.inria.fr/doxygen/visp-daily/index.html).


This project uses [ViSP](https://github.com/lagadic/visp) as 3rd-party.

## Build visp_sample with ViSP build tree

See ViSP installation from source [tutorials](https://visp-doc.inria.fr/doxygen/visp-daily/tutorial_install_src.html).

Once ViSP is build, you can build `visp_sample` project:

```
$ cd $ViSP_WS
$ git clone https://github.com/lagadic/visp_sample
$ mkdir visp_sample-build
$ cd visp_sample-build
$ cmake ../visp_sample -DVISP_DIR=$ViSP_WS/visp-build
```

## Build visp_sample with ViSP install tree

- build and install ViSP

```
$ cd $ViSP_WS/visp-build
$ cmake ../visp -DCMAKE_INSTALL_PREFIX=/tmp/usr/local
$ make -j4
$ make -j4 install
```

- build `visp_sample` using `cmake`

```
$ cd $ViSP_WS/visp_sample
$ mkdir build
$ cd build
$ cmake ../ -DVISP_DIR=/tmp/usr/local/lib/
$ make -j4
```

- build `visp_sample` using `visp-config`

```
$ cd $ViSP_WS/visp_sample
$ export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/tmp/usr/local/lib/pkgconfig
$ make -j4 -f Makefile.visp-config
$ make -j4 -f Makefile.visp-config clean
```

- build `visp_sample` using `visp.pc`

```
$ cd $ViSP_WS/visp_sample
$ export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/tmp/usr/local/lib/pkgconfig
$ make -j4 -f Makefile.visp.pc
$ make -j4 -f Makefile.visp.pc clean
```


