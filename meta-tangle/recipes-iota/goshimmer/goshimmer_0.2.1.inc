require goshimmer-common.inc

# Go dependencies
SRC_URI += " \
        git://github.com/StackExchange/wmi.git;protocol=https;name=wmi;destsuffix=${PN}-${PV}/src/github.com/StackExchange/wmi;nobranch=1 \
        git://github.com/dgraph-io/badger.git;protocol=https;name=badger;destsuffix=${PN}-${PV}/src/github.com/dgraph-io/badger/v2;nobranch=1 \
        git://github.com/dgrijalva/jwt-go.git;protocol=https;name=jwt-go;destsuffix=${PN}-${PV}/src/github.com/dgrijalva/jwt-go \
        git://github.com/gobuffalo/packr.git;protocol=https;name=packr;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/packr \
        git://github.com/gobuffalo/logger.git;protocol=https;name=logger;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/logger \
        git://github.com/protocolbuffers/protobuf-go.git;protocol=https;name=protobuf_google;destsuffix=${PN}-${PV}/src/google.golang.org/protobuf \
        git://github.com/golang/protobuf.git;protocol=https;name=protobuf_github;destsuffix=${PN}-${PV}/src/github.com/golang/protobuf \
        git://github.com/gorilla/websocket.git;protocol=https;name=websocket;destsuffix=${PN}-${PV}/src/github.com/gorilla/websocket \
        git://github.com/iotaledger/hive.go.git;protocol=https;name=hive.go;destsuffix=${PN}-${PV}/src/github.com/iotaledger/hive.go \
        git://github.com/iotaledger/iota.go.git;protocol=https;name=iota.go;destsuffix=${PN}-${PV}/src/github.com/iotaledger/iota.go \
        git://github.com/labstack/echo.git;protocol=https;name=echo;destsuffix=${PN}-${PV}/src/github.com/labstack/echo \
        git://github.com/labstack/gommon.git;protocol=https;name=gommon;destsuffix=${PN}-${PV}/src/github.com/labstack/gommon \
        git://github.com/magiconair/properties.git;protocol=https;name=properties;destsuffix=${PN}-${PV}/src/github.com/magiconair/properties \
	git://github.com/mr-tron/base58.git;protocol=https;name=base58;destsuffix=${PN}-${PV}/src/github.com/mr-tron/base58 \
	git://github.com/panjf2000/ants.git;protocol=https;name=ants;destsuffix=${PN}-${PV}/src/github.com/panjf2000/ants \
        git://github.com/pkg/errors.git;protocol=https;name=errors;destsuffix=${PN}-${PV}/src/github.com/pkg/errors \
        git://github.com/spf13/pflag.git;protocol=https;name=pflag;destsuffix=${PN}-${PV}/src/github.com/spf13/pflag \
        git://github.com/spf13/viper.git;protocol=https;name=viper;destsuffix=${PN}-${PV}/src/github.com/spf13/viper \
        git://github.com/stretchr/testify.git;protocol=https;name=testify;destsuffix=${PN}-${PV}/src/github.com/stretchr/testify \
        git://github.com/valyala/fasttemplate.git;protocol=https;name=fasttemplate;destsuffix=${PN}-${PV}/src/github.com/valyala/fasttemplate \
        git://github.com/uber-go/atomic.git;protocol=https;name=atomic;destsuffix=${PN}-${PV}/src/go.uber.org/atomic \
        git://github.com/uber-go/zap.git;protocol=https;name=zap;destsuffix=${PN}-${PV}/src/go.uber.org/zap \
        git://github.com/golang/crypto.git;protocol=https;name=crypto;destsuffix=${PN}-${PV}/src/golang.org/x/crypto \
        git://github.com/golang/net.git;protocol=https;name=net;destsuffix=${PN}-${PV}/src/golang.org/x/net \
        git://github.com/golang/sys.git;protocol=https;name=sys;destsuffix=${PN}-${PV}/src/golang.org/x/sys \
	git://github.com/golang/text.git;protocol=https;name=text;destsuffix=${PN}-${PV}/src/golang.org/x/text \
        git://github.com/go-ini/ini.git;protocol=https;name=ini.v1;destsuffix=${PN}-${PV}/src/gopkg.in/ini.v1 \
	git://github.com/src-d/go-git.git;protocol=https;name=go-git;destsuffix=${PN}-${PV}/src/gopkg.in/src-d/go-git.v4 \
        git://github.com/DataDog/zstd.git;protocol=https;name=zstd;destsuffix=${PN}-${PV}/src/github.com/DataDog/zstd;nobranch=1 \
        git://github.com/cespare/xxhash.git;protocol=https;name=xxhash;destsuffix=${PN}-${PV}/src/github.com/cespare/xxhash \
        git://github.com/dgraph-io/ristretto.git;protocol=https;name=ristretto;destsuffix=${PN}-${PV}/src/github.com/dgraph-io/ristretto \
        git://github.com/dustin/go-humanize.git;protocol=https;name=go-humanize;destsuffix=${PN}-${PV}/src/github.com/dustin/go-humanize \
        git://github.com/fsnotify/fsnotify.git;protocol=https;name=fsnotify;destsuffix=${PN}-${PV}/src/github.com/fsnotify/fsnotify \
        git://github.com/golang/snappy.git;protocol=https;name=snappy;destsuffix=${PN}-${PV}/src/github.com/golang/snappy \
        git://github.com/valyala/bytebufferpool.git;protocol=https;name=bytebufferpool;destsuffix=${PN}-${PV}/src/github.com/valyala/bytebufferpool \
        git://github.com/uber-go/multierr.git;protocol=https;name=multierr;destsuffix=${PN}-${PV}/src/go.uber.org/multierr \
        git://github.com/gobuffalo/packd.git;protocol=https;name=packd;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/packd \
        git://github.com/hashicorp/hcl.git;protocol=https;name=hcl;destsuffix=${PN}-${PV}/src/github.com/hashicorp/hcl \
        git://github.com/mitchellh/mapstructure.git;protocol=https;name=mapstructure;destsuffix=${PN}-${PV}/src/github.com/mitchellh/mapstructure \
        git://github.com/subosito/gotenv.git;protocol=https;name=gotenv;destsuffix=${PN}-${PV}/src/github.com/subosito/gotenv \
	git://github.com/emirpasic/gods.git;protocol=https;name=gods;destsuffix=${PN}-${PV}/src/github.com/emirpasic/gods \
	git://github.com/jbenet/go-context.git;protocol=https;name=go-context;destsuffix=${PN}-${PV}/src/github.com/jbenet/go-context \
	git://github.com/kevinburke/ssh_config.git;protocol=https;name=ssh_config;destsuffix=${PN}-${PV}/src/github.com/kevinburke/ssh_config \
	git://github.com/mitchellh/go-homedir.git;protocol=https;name=go-homedir;destsuffix=${PN}-${PV}/src/github.com/mitchellh/go-homedir \
	git://github.com/src-d/gcfg.git;protocol=https;name=gcfg;destsuffix=${PN}-${PV}/src/github.com/src-d/gcfg;nobranch=1 \
	git://github.com/xanzy/ssh-agent.git;protocol=https;name=ssh-agent;destsuffix=${PN}-${PV}/src/github.com/xanzy/ssh-agent \
	git://github.com/src-d/go-billy.git;protocol=https;name=go-billy;destsuffix=${PN}-${PV}/src/gopkg.in/src-d/go-billy.v4 \
	git://github.com/go-warnings/warnings.git;protocol=https;name=warnings;destsuffix=${PN}-${PV}/src/gopkg.in/warnings.v0 \
        git://github.com/karrick/godirwalk.git;protocol=https;name=godirwalk;destsuffix=${PN}-${PV}/src/github.com/karrick/godirwalk \
        git://github.com/markbates/errx.git;protocol=https;name=errx;destsuffix=${PN}-${PV}/src/github.com/markbates/errx \
        git://github.com/markbates/oncer.git;protocol=https;name=oncer;destsuffix=${PN}-${PV}/src/github.com/markbates/oncer \
        git://github.com/markbates/safe.git;protocol=https;name=safe;destsuffix=${PN}-${PV}/src/github.com/markbates/safe \
        git://github.com/sirupsen/logrus.git;protocol=https;name=logrus;destsuffix=${PN}-${PV}/src/github.com/sirupsen/logrus \
        git://github.com/drand/drand.git;protocol=https;name=drand;destsuffix=${PN}-${PV}/src/github.com/drand/drand;nobranch=1 \
	git://github.com/drand/kyber.git;protocol=https;name=kyber_drand;destsuffix=${PN}-${PV}/src/github.com/drand/kyber;nobranch=1 \
	git://github.com/dedis/kyber.git;protocol=https;name=kyber_dedis;destsuffix=${PN}-${PV}/src/go.dedis.ch/kyber;nobranch=1 \
        git://github.com/gin-gonic/gin.git;protocol=https;name=gin;destsuffix=${PN}-${PV}/src/github.com/gin-gonic/gin;nobranch=1 \
	git://github.com/go-ole/go-ole.git;protocol=https;name=go-ole;destsuffix=${PN}-${PV}/src/github.com/go-ole/go-ole;nobranch=1 \
	git://github.com/prometheus/client_golang.git;protocol=https;name=prometheus;destsuffix=${PN}-${PV}/src/github.com/prometheus/client_golang;nobranch=1 \
	git://github.com/shirou/gopsutil.git;protocol=https;name=gopsutil;destsuffix=${PN}-${PV}/src/github.com/shirou/gopsutil;nobranch=1 \
	git://github.com/BurntSushi/toml.git;protocol=https;name=toml;destsuffix=${PN}-${PV}/src/github.com/BurntSushi/toml;nobranch=1 \
	git://github.com/beorn7/perks.git;protocol=https;name=perks;destsuffix=${PN}-${PV}/src/github.com/beorn7/perks;nobranch=1 \
	git://github.com/coreos/bbolt.git;protocol=https;name=bbolt;destsuffix=${PN}-${PV}/src/github.com/coreos/bbolt;nobranch=1 \
	git://github.com/dchest/blake2b.git;protocol=https;name=blake2b;destsuffix=${PN}-${PV}/src/github.com/dchest/blake2b;nobranch=1 \
	git://github.com/dgryski/go-farm.git;protocol=https;name=go-farm;destsuffix=${PN}-${PV}/src/github.com/dgryski/go-farm \
	git://github.com/drand/bls12-381.git;protocol=https;name=bls12-381;destsuffix=${PN}-${PV}/src/github.com/drand/bls12-381;nobranch=1 \
	git://github.com/gin-contrib/sse.git;protocol=https;name=sse;destsuffix=${PN}-${PV}/src/github.com/gin-contrib/sse;nobranch=1 \
	git://github.com/go-kit/kit.git;protocol=https;name=kit;destsuffix=${PN}-${PV}/src/github.com/go-kit/kit;nobranch=1 \
	git://github.com/go-logfmt/logfmt.git;protocol=https;name=logfmt;destsuffix=${PN}-${PV}/src/github.com/go-logfmt/logfmt;nobranch=1 \
	git://github.com/go-playground/validator.git;protocol=https;name=validator;destsuffix=${PN}-${PV}/src/github.com/go-playground/validator/v10;nobranch=1 \
	git://github.com/go-playground/universal-translator.git;protocol=https;name=universal-translator;destsuffix=${PN}-${PV}/src/github.com/go-playground/universal-translator;nobranch=1 \
	git://github.com/go-playground/locales.git;protocol=https;name=locales;destsuffix=${PN}-${PV}/src/github.com/go-playground/locales;nobranch=1 \
	git://github.com/grpc-ecosystem/go-grpc-prometheus.git;protocol=https;name=go-grpc-prometheus;destsuffix=${PN}-${PV}/src/github.com/grpc-ecosystem/go-grpc-prometheus;nobranch=1 \
	git://github.com/grpc-ecosystem/grpc-gateway.git;protocol=https;name=grpc-gateway;destsuffix=${PN}-${PV}/src/github.com/grpc-ecosystem/grpc-gateway;nobranch=1 \
	git://github.com/jonboulle/clockwork.git;protocol=https;name=clockwork;destsuffix=${PN}-${PV}/src/github.com/jonboulle/clockwork;nobranch=1 \
	git://github.com/kr/text.git;protocol=https;name=krtext;destsuffix=${PN}-${PV}/src/github.com/kr/text;nobranch=1 \
	git://github.com/leodido/go-urn.git;protocol=https;name=go-urn;destsuffix=${PN}-${PV}/src/github.com/leodido/go-urn;nobranch=1 \
	git://github.com/mattn/go-colorable.git;protocol=https;name=go-colorable;destsuffix=${PN}-${PV}/src/github.com/mattn/go-colorable;nobranch=1 \
	git://github.com/mattn/go-isatty.git;protocol=https;name=go-isatty;destsuffix=${PN}-${PV}/src/github.com/mattn/go-isatty;nobranch=1 \
	git://github.com/nikkolasg/hexjson.git;protocol=https;name=hexjson;destsuffix=${PN}-${PV}/src/github.com/nikkolasg/hexjson;nobranch=1 \
	git://github.com/nikkolasg/slog.git;protocol=https;name=slog;destsuffix=${PN}-${PV}/src/github.com/nikkolasg/slog;nobranch=1 \
	git://github.com/oasisprotocol/ed25519.git;protocol=https;name=ed25519;destsuffix=${PN}-${PV}/src/github.com/oasisprotocol/ed25519 \
        git://github.com/pelletier/go-toml.git;protocol=https;name=go-toml;destsuffix=${PN}-${PV}/src/github.com/pelletier/go-toml \
	git://github.com/prometheus/client_model.git;protocol=https;name=prometheus_model;destsuffix=${PN}-${PV}/src/github.com/prometheus/client_model;nobranch=1 \
	git://github.com/prometheus/common.git;protocol=https;name=prometheus_common;destsuffix=${PN}-${PV}/src/github.com/prometheus/common;nobranch=1 \
	git://github.com/matttproud/golang_protobuf_extensions.git;protocol=https;name=golang_protobuf_extensions;destsuffix=${PN}-${PV}/src/github.com/matttproud/golang_protobuf_extensions;nobranch=1 \
	git://github.com/prometheus/procfs.git;protocol=https;name=prometheus_procfs;destsuffix=${PN}-${PV}/src/github.com/prometheus/procfs;nobranch=1 \
	git://github.com/go-yaml/yaml.git;protocol=https;name=yamlv3;destsuffix=${PN}-${PV}/src/gopkg.in/yaml.v3;nobranch=1 \
        git://github.com/go-yaml/yaml.git;protocol=https;name=yamlv2;destsuffix=${PN}-${PV}/src/gopkg.in/yaml.v2;nobranch=1 \
	git://github.com/sergi/go-diff.git;protocol=https;name=go-diff;destsuffix=${PN}-${PV}/src/github.com/sergi/go-diff \
	git://github.com/soheilhy/cmux.git;protocol=https;name=cmux;destsuffix=${PN}-${PV}/src/github.com/soheilhy/cmux;nobranch=1 \
	git://github.com/pmezard/go-difflib.git;protocol=https;name=go-difflib;destsuffix=${PN}-${PV}/src/github.com/pmezard/go-difflib;nobranch=1 \
	git://github.com/spf13/afero.git;protocol=https;name=afero;destsuffix=${PN}-${PV}/src/github.com/spf13/afero \
	git://github.com/davecgh/go-spew.git;protocol=https;name=go-spew;destsuffix=${PN}-${PV}/src/github.com/davecgh/go-spew;nobranch=1 \
	git://github.com/spf13/cast.git;protocol=https;name=cast;destsuffix=${PN}-${PV}/src/github.com/spf13/cast \
	git://github.com/spf13/jwalterweatherman.git;protocol=https;name=jwalterweatherman;destsuffix=${PN}-${PV}/src/github.com/spf13/jwalterweatherman \
	git://github.com/ugorji/go.git;protocol=https;name=go-codec;destsuffix=${PN}-${PV}/src/github.com/ugorji/go;nobranch=1 \
	git://github.com/dedis/fixbuf.git;protocol=https;name=fixbuf;destsuffix=${PN}-${PV}/src/go.dedis.ch/fixbuf;nobranch=1 \
	git://github.com/dedis/protobuf.git;protocol=https;name=protobuf_dedis;destsuffix=${PN}-${PV}/src/go.dedis.ch/protobuf;nobranch=1 \
	git://github.com/mongodb/mongo-go-driver.git;protocol=https;name=mongodb;destsuffix=${PN}-${PV}/src/go.mongodb.org/mongo-driver;nobranch=1 \
	git://github.com/googleapis/go-genproto.git;protocol=https;name=genproto;destsuffix=${PN}-${PV}/src/google.golang.org/genproto;nobranch=1 \
	git://github.com/grpc/grpc-go.git;protocol=https;name=grpc;destsuffix=${PN}-${PV}/src/google.golang.org/grpc;nobranch=1 \
"

SRCREV_goshimmer = "v${PV}"

# goshimmer deps
SRCREV_wmi = "cbe66965904dbe8a6cd589e2298e5d8b986bd7dd"
SRCREV_badger = "v2.0.3"
SRCREV_jwt-go = "v3.2.0"
SRCREV_packr = "v2.8.0"
SRCREV_drand = "v0.8.1"
SRCREV_kyber_drand = "30e90cc60f99892f0f331a6fe8f02c7da448a52b"
SRCREV_kyber_dedis = "v3.0.12"
SRCREV_gin = "v1.6.3"
SRCREV_go-ole = "v1.2.4"
SRCREV_protobuf_github = "v1.4.2"
SRCREV_protobuf_google = "v1.23.0"
SRCREV_websocket = "v1.4.2"
SRCREV_hive.go = "310ea88f133773290947526c708a630109269708"
SRCREV_iota.go = "v1.0.0-beta.14"
SRCREV_echo = "v3.3.10"
SRCREV_gommon = "v0.3.0"
SRCREV_properties = "v1.8.1"
SRCREV_base58 = "v1.2.0"
SRCREV_ants = "v2.4.1"
SRCREV_errors = "v0.8.1"
SRCREV_pflag = "v1.0.5"
SRCREV_viper = "v1.7.0"
SRCREV_testify = "v1.6.1"
SRCREV_fasttemplate = "v1.1.0"
SRCREV_atomic = "v1.5.1"
SRCREV_zap = "v1.15.0"
SRCREV_crypto = "70a84ac30bf957c7df57edd1935d2081871515e1"
SRCREV_net = "ff2c4b7c35a07b0c1e90ce72aa7bfe41bb66a3cb"
SRCREV_sys = "12a6c2dcc1e4cb348b57847c73987099e261714b"
SRCREV_text = "v0.3.2"
SRCREV_ini.v1 = "v1.51.1"
SRCREV_go-git = "v4.13.1"
SRCREV_prometheus = "v1.7.0"
SRCREV_gopsutil = "v2.20.5"
SRCREV_mongodb = "v1.3.4"
SRCREV_grpc = "v1.30.0"

# badger deps
SRCREV_zstd = "v1.4.1"
SRCREV_xxhash = "v2.1.1"
SRCREV_ristretto = "8f368f2f2ab3a54cbe62fb9772cd75ce55e07802"
SRCREV_go-humanize = "v1.0.0"
SRCREV_snappy = "v0.0.1"
SRCREV_go-farm = "c2139c5d712b01d0410c2e51d4bdc588b4eb6ca3"

# viper deps
SRCREV_fsnotify = "v1.4.7"
SRCREV_hcl = "v1.0.0"
SRCREV_mapstructure = "v1.1.2"
SRCREV_gotenv = "v1.2.0"
SRCREV_go-toml = "v1.2.0"
SRCREV_afero = "v1.1.2"
SRCREV_cast = "v1.3.0"
SRCREV_jwalterweatherman = "v1.0.0"
SRCREV_yamlv2 = "v2.2.4"

# fasttemplate deps
SRCREV_bytebufferpool = "v1.0.0"

# zap deps
SRCREV_multierr = "v1.3.0"

# packr deps
SRCREV_packd = "v0.3.0"
SRCREV_logger = "v1.0.3"
SRCREV_godirwalk = "v1.15.3"
SRCREV_errx = "v1.1.0"
SRCREV_oncer = "v1.0.0"
SRCREV_safe = "v1.0.1"

# logger deps
SRCREV_logrus = "v1.4.2"

# go-git deps
SRCREV_gods = "v1.12.0"
SRCREV_go-context = "d14ea06fba99483203c19d92cfcd13ebe73135f4"
SRCREV_ssh_config = "01f96b0aa0cdcaa93f9495f89bbc6cb5a992ce6e"
SRCREV_go-homedir = "v1.1.0"
SRCREV_gcfg = "v1.4.0"
SRCREV_ssh-agent = "v0.2.1"
SRCREV_go-billy = "v4.3.2"
SRCREV_go-diff = "v1.0.0"

# gcfg deps
SRCREV_warnings = "v0.1.2"

# drand deps
SRCREV_toml = "v0.3.1"
SRCREV_bbolt = "v1.3.2"
SRCREV_blake2b = "v1.0.0"
SRCREV_bls12-381 = "v0.3.2"
SRCREV_kit = "v0.9.0"
SRCREV_go-grpc-prometheus = "v1.2.0"
SRCREV_grpc-gateway = "v1.14.3"
SRCREV_clockwork = "62fb9bc030d14f92c58df3c1601e50a0e445edef"
SRCREV_hexjson = "78e39397e00c19adc06d5f44810e4694f251866d"
SRCREV_slog = "3c8d441d7a1e2d4104741afd74893eaac3f5320f"
SRCREV_cmux = "v0.1.4"
SRCREV_genproto = "33397c535dc2c2a2b6e751a1aca1bc59f3f7859d"

# prometheus deps
SRCREV_perks = "v1.0.1"
SRCREV_prometheus_model = "v0.2.0"
SRCREV_prometheus_common = "v0.10.0"
SRCREV_prometheus_procfs = "v0.1.3"
SRCREV_golang_protobuf_extensions = "v1.0.1"

# gin deps
SRCREV_sse = "v0.1.0"
SRCREV_validator = "v10.2.0"
SRCREV_go-codec = "v1.1.7"

# kit deps
SRCREV_logfmt = "v0.5.0"

# validator deps
SRCREV_universal-translator = "v0.17.0"
SRCREV_go-urn = "v1.2.0"

# universal-translator deps
SRCREV_locales = "v0.13.0"

# hive deps
SRCREV_krtext = "v0.2.0"
SRCREV_ed25519 = "55566edd6df0c8648707d0f014e771244cb9137f"

# gommon deps
SRCREV_go-colorable = "v0.1.2"

# go-colorable deps
SRCREV_go-isatty = "v0.0.8"

# testify deps
SRCREV_yamlv3 = "eeeca48fe7764f320e4870d231902bf9c1be2c08"
SRCREV_go-difflib = "v1.0.0"
SRCREV_go-spew = "v1.1.0"

# kyber_dedis deps
SRCREV_fixbuf = "v1.0.3"
SRCREV_protobuf_dedis = "v1.0.5"
