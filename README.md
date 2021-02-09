# visp_sample

ViSP sample code used as code snippet in ViSP doxygen [documentation](https://visp-doc.inria.fr/doxygen/visp-daily/index.html).

This project uses [ViSP](https://github.com/lagadic/visp) that needs to be build with the following as 3rd-parties:
- OpenCV
- librealsense
- libxml2
- PCL

## 1. Prerequisities

### 1.1. Install required 3rd parties

- On ubuntu

  - Install required packages:

    ```
    $ sudo apt-get update
    $ sudo apt-get install pkg-config libopencv-dev libxml2-dev libpcl-dev
    ```

  - Install librealsense from source following these [instructions](https://visp-doc.inria.fr/doxygen/visp-daily/tutorial-install-ubuntu.html#install_ubuntu_3rdparty_realsense)

- On OSX
```
$ brew update; brew upgrade
$ brew install opencv librealsense libxml2 pcl
```

### 1.2. Build and install ViSP from source

See ViSP installation from source [tutorials](https://visp-doc.inria.fr/doxygen/visp-daily/tutorial_install_src.html).

```
$ cd $VISP_WS
$ git clone https://github.com/lagadic/visp.git
$ mkdir $VISP_WS/visp-build
$ cd $VISP_WS/visp-build
$ cmake ../visp -DCMAKE_INSTALL_PREFIX=/tmp/usr/local
$ make -j4 install
```

Once ViSP is build, you can build `visp_sample` project using one of the 5 different ways that are given in the next sections.

## 2. Build visp_sample project

### 2.1. Build visp_sample with ViSP from build tree

```
$ cd $ViSP_WS
$ git clone https://github.com/lagadic/visp_sample
$ mkdir visp_sample-build
$ cd visp_sample-build
$ cmake ../visp_sample -DVISP_DIR=$ViSP_WS/visp-build
```

### 2.2. Build visp_sample using `visp-config` from build tree

```
$ cd $ViSP_WS/visp_sample
$ make -f Makefile.visp-config VISP_INSTALL_PREFIX=$ViSP_WS/visp-build
$ make -f Makefile.visp-config clean
```

### 2.3. Build visp_sample with ViSP from install tree

```
$ cd $ViSP_WS
$ git clone https://github.com/lagadic/visp_sample
$ mkdir visp_sample-build
$ cd visp_sample-build
$ cmake ../visp_sample -DVISP_DIR=/tmp/usr/local/lib/cmake/visp
```

### 2.4. Build visp_sample using `visp.pc` from install tree

```
$ cd $ViSP_WS/visp_sample
$ export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/tmp/usr/local/lib/pkgconfig
$ make -f Makefile.visp.pc
$ make -f Makefile.visp.pc clean
```

### 2.5. Build visp_sample using `visp-config` from install tree

```
$ cd $ViSP_WS/visp_sample
$ export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/tmp/usr/local/lib/pkgconfig
$ make -f Makefile.visp-config VISP_INSTALL_PREFIX=/tmp/usr/local
$ make -f Makefile.visp-config clean
```
