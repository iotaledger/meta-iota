require hornet-common.inc

# Go dependencies
SRC_URI += "\
           git://github.com/cespare/xxhash.git;protocol=https;name=xxhash;destsuffix=${PN}-${PV}/src/github.com/cespare/xxhash \
           git://github.com/dgraph-io/badger.git;protocol=https;name=badger;destsuffix=${PN}-${PV}/src/github.com/dgraph-io/badger/v2;nobranch=1 \
           git://github.com/eclipse/paho.mqtt.golang.git;protocol=https;name=paho.mqtt;destsuffix=${PN}-${PV}/src/github.com/eclipse/paho.mqtt.golang \
           git://github.com/fhmq/hmq.git;protocol=https;name=hmq;destsuffix=${PN}-${PV}/src/github.com/fhmq/hmq \
           git://github.com/gin-contrib/gzip.git;protocol=https;name=gzip;destsuffix=${PN}-${PV}/src/github.com/gin-contrib/gzip \
           git://github.com/gin-gonic/gin.git;protocol=https;name=gin;destsuffix=${PN}-${PV}/src/github.com/gin-gonic/gin \
           git://github.com/go-zeromq/zmq4.git;protocol=https;name=zmq4;destsuffix=${PN}-${PV}/src/github.com/go-zeromq/zmq4 \
           git://github.com/gobuffalo/packr.git;protocol=https;name=packr;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/packr \
           git://github.com/google/go-github.git;protocol=https;name=go-github;destsuffix=${PN}-${PV}/src/github.com/google/go-github \
           git://github.com/google/go-querystring.git;protocol=https;name=go-querystring;destsuffix=${PN}-${PV}/src/github.com/google/go-querystring \
           git://github.com/hashicorp/go-version.git;protocol=https;name=go-version;destsuffix=${PN}-${PV}/src/github.com/hashicorp/go-version \
           git://github.com/gorilla/websocket.git;protocol=https;name=websocket;destsuffix=${PN}-${PV}/src/github.com/gorilla/websocket \
           git://github.com/iotaledger/hive.go.git;protocol=https;name=hive.go;destsuffix=${PN}-${PV}/src/github.com/iotaledger/hive.go \
           git://github.com/iotaledger/iota.go.git;protocol=https;name=iota.go;destsuffix=${PN}-${PV}/src/github.com/iotaledger/iota.go \
           git://github.com/labstack/echo.git;protocol=https;name=echo;destsuffix=${PN}-${PV}/src/github.com/labstack/echo \
           git://github.com/mitchellh/mapstructure.git;protocol=https;name=mapstructure;destsuffix=${PN}-${PV}/src/github.com/mitchellh/mapstructure \
           git://github.com/pkg/errors.git;protocol=https;name=errors;destsuffix=${PN}-${PV}/src/github.com/pkg/errors \
           git://github.com/projectcalico/libcalico-go.git;protocol=https;name=libcalico-go;destsuffix=${PN}-${PV}/src/github.com/projectcalico/libcalico-go \
           git://github.com/shirou/gopsutil.git;protocol=https;name=gopsutil;destsuffix=${PN}-${PV}/src/github.com/shirou/gopsutil \
           git://github.com/spf13/pflag.git;protocol=https;name=pflag;destsuffix=${PN}-${PV}/src/github.com/spf13/pflag \
           git://github.com/golang/net.git;protocol=https;name=net;destsuffix=${PN}-${PV}/src/golang.org/x/net \
           git://github.com/tcnksm/go-latest.git;protocol=https;name=go-latest;destsuffix=${PN}-${PV}/src/github.com/tcnksm/go-latest \
           git://github.com/dgrijalva/jwt-go.git;protocol=https;name=jwt-go;destsuffix=${PN}-${PV}/src/github.com/dgrijalva/jwt-go \
           git://github.com/dustin/go-humanize.git;protocol=https;name=go-humanize;destsuffix=${PN}-${PV}/src/github.com/dustin/go-humanize \
           git://github.com/gin-contrib/sse.git;protocol=https;name=sse;destsuffix=${PN}-${PV}/src/github.com/gin-contrib/sse \
           git://github.com/gobuffalo/envy.git;protocol=https;name=envy;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/envy \
           git://github.com/gobuffalo/logger.git;protocol=https;name=logger;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/logger \
           git://github.com/gobuffalo/packd.git;protocol=https;name=packd;destsuffix=${PN}-${PV}/src/github.com/gobuffalo/packd \
           git://github.com/joho/godotenv.git;protocol=https;name=godotenv;destsuffix=${PN}-${PV}/src/github.com/joho/godotenv \
           git://github.com/mattn/go-isatty.git;protocol=https;name=go-isatty;destsuffix=${PN}-${PV}/src/github.com/mattn/go-isatty \
           git://github.com/rogpeppe/go-internal.git;protocol=https;name=go-internal;destsuffix=${PN}-${PV}/src/github.com/rogpeppe/go-internal \
           git://github.com/sirupsen/logrus.git;protocol=https;name=logrus;destsuffix=${PN}-${PV}/src/github.com/sirupsen/logrus \
           git://github.com/spf13/viper.git;protocol=https;name=viper;destsuffix=${PN}-${PV}/src/github.com/spf13/viper \
           git://github.com/fsnotify/fsnotify.git;protocol=https;name=fsnotify;destsuffix=${PN}-${PV}/src/github.com/fsnotify/fsnotify \
           git://github.com/hashicorp/hcl.git;protocol=https;name=hcl;destsuffix=${PN}-${PV}/src/github.com/hashicorp/hcl \
           git://github.com/magiconair/properties.git;protocol=https;name=properties;destsuffix=${PN}-${PV}/src/github.com/magiconair/properties \
           git://github.com/pelletier/go-toml.git;protocol=https;name=go-toml;destsuffix=${PN}-${PV}/src/github.com/pelletier/go-toml \
           git://github.com/spf13/afero.git;protocol=https;name=afero;destsuffix=${PN}-${PV}/src/github.com/spf13/afero \
           git://github.com/spf13/cast.git;protocol=https;name=cast;destsuffix=${PN}-${PV}/src/github.com/spf13/cast \
           git://github.com/spf13/jwalterweatherman.git;protocol=https;name=jwalterweatherman;destsuffix=${PN}-${PV}/src/github.com/spf13/jwalterweatherman \
           git://github.com/subosito/gotenv.git;protocol=https;name=gotenv;destsuffix=${PN}-${PV}/src/github.com/subosito/gotenv \
           git://github.com/json-iterator/go.git;protocol=https;name=json-iterator;destsuffix=${PN}-${PV}/src/github.com/json-iterator/go \
           git://github.com/ugorji/go.git;protocol=https;name=go-codec;destsuffix=${PN}-${PV}/src/github.com/ugorji/go \
           git://github.com/golang/xerrors.git;protocol=https;name=xerrors;destsuffix=${PN}-${PV}/src/golang.org/x/xerrors \
           git://github.com/go-playground/validator.git;protocol=https;name=validator;destsuffix=${PN}-${PV}/src/gopkg.in/go-playground/validator.v9 \
           git://github.com/go-playground/universal-translator.git;protocol=https;name=universal-translator;destsuffix=${PN}-${PV}/src/github.com/go-playground/universal-translator \
           git://github.com/go-playground/locales.git;protocol=https;name=locales;destsuffix=${PN}-${PV}/src/github.com/go-playground/locales \
           git://github.com/leodido/go-urn.git;protocol=https;name=go-urn;destsuffix=${PN}-${PV}/src/github.com/leodido/go-urn \
           git://github.com/go-yaml/yaml.git;protocol=https;name=yaml;destsuffix=${PN}-${PV}/src/gopkg.in/yaml.v2;nobranch=1 \
           git://github.com/golang/protobuf.git;protocol=https;name=protobuf;destsuffix=${PN}-${PV}/src/github.com/golang/protobuf \
           git://github.com/Shopify/sarama.git;protocol=https;name=sarama;destsuffix=${PN}-${PV}/src/github.com/Shopify/sarama \
           git://github.com/bitly/go-simplejson.git;protocol=https;name=go-simplejson;destsuffix=${PN}-${PV}/src/github.com/bitly/go-simplejson \
           git://github.com/davecgh/go-spew.git;protocol=https;name=go-spew;destsuffix=${PN}-${PV}/src/github.com/davecgh/go-spew \
           git://github.com/eapache/go-resiliency.git;protocol=https;name=go-resiliency;destsuffix=${PN}-${PV}/src/github.com/eapache/go-resiliency \
           git://github.com/eapache/go-resiliency.git;protocol=https;name=go-resiliency;destsuffix=${PN}-${PV}/src/github.com/eapache/go-resiliency \
           git://github.com/eapache/go-xerial-snappy.git;protocol=https;name=go-xerial-snappy;destsuffix=${PN}-${PV}/src/github.com/eapache/go-xerial-snappy \
           git://github.com/eapache/queue.git;protocol=https;name=queue;destsuffix=${PN}-${PV}/src/github.com/eapache/queue \
           git://github.com/golang/snappy.git;protocol=https;name=snappy;destsuffix=${PN}-${PV}/src/github.com/golang/snappy \
           git://github.com/jcmturner/gofork.git;protocol=https;name=gofork;destsuffix=${PN}-${PV}/src/github.com/jcmturner/gofork \
           git://github.com/patrickmn/go-cache.git;protocol=https;name=go-cache;destsuffix=${PN}-${PV}/src/github.com/patrickmn/go-cache \
           git://github.com/pierrec/lz4.git;protocol=https;name=lz4;destsuffix=${PN}-${PV}/src/github.com/pierrec/lz4 \
           git://github.com/rcrowley/go-metrics.git;protocol=https;name=go-metrics;destsuffix=${PN}-${PV}/src/github.com/rcrowley/go-metrics \
           git://github.com/satori/go.uuid.git;protocol=https;name=go.uuid;destsuffix=${PN}-${PV}/src/github.com/satori/go.uuid \
           git://github.com/segmentio/fasthash.git;protocol=https;name=fasthash;destsuffix=${PN}-${PV}/src/github.com/segmentio/fasthash \
           git://github.com/tidwall/gjson.git;protocol=https;name=gjson;destsuffix=${PN}-${PV}/src/github.com/tidwall/gjson \
           git://github.com/uber-go/zap.git;protocol=https;name=zap;destsuffix=${PN}-${PV}/src/go.uber.org/zap \
           git://github.com/tidwall/match.git;protocol=https;name=match;destsuffix=${PN}-${PV}/src/github.com/tidwall/match \
           git://github.com/tidwall/pretty.git;protocol=https;name=pretty;destsuffix=${PN}-${PV}/src/github.com/tidwall/pretty \
           git://github.com/uber-go/multierr.git;protocol=https;name=multierr;destsuffix=${PN}-${PV}/src/go.uber.org/multierr \
           git://github.com/golang/crypto.git;protocol=https;name=crypto;destsuffix=${PN}-${PV}/src/golang.org/x/crypto \
           git://github.com/golang/sync.git;protocol=https;name=sync;destsuffix=${PN}-${PV}/src/golang.org/x/sync\
           git://github.com/golang/text.git;protocol=https;name=text;destsuffix=${PN}-${PV}/src/golang.org/x/text \
           git://github.com/go-ini/ini.git;protocol=https;name=ini.v1;destsuffix=${PN}-${PV}/src/gopkg.in/ini.v1 \
           git://github.com/jcmturner/gokrb5.git;protocol=https;name=gokrb5;destsuffix=${PN}-${PV}/src/gopkg.in/jcmturner/gokrb5.v7 \
           git://github.com/hashicorp/go-uuid.git;protocol=https;name=go-uuid;destsuffix=${PN}-${PV}/src/github.com/hashicorp/go-uuid \
           git://github.com/jcmturner/aescts.git;protocol=https;name=aescts;destsuffix=${PN}-${PV}/src/gopkg.in/jcmturner/aescts.v1 \
           git://github.com/jcmturner/dnsutils.git;protocol=https;name=dnsutils;destsuffix=${PN}-${PV}/src/gopkg.in/jcmturner/dnsutils.v1 \
           git://github.com/jcmturner/rpc.git;protocol=https;name=rpc;destsuffix=${PN}-${PV}/src/gopkg.in/jcmturner/rpc.v1 \
           git://github.com/DataDog/zstd.git;protocol=https;name=zstd;destsuffix=${PN}-${PV}/src/github.com/DataDog/zstd;nobranch=1 \
           git://github.com/dgraph-io/ristretto.git;protocol=https;name=ristretto;destsuffix=${PN}-${PV}/src/github.com/dgraph-io/ristretto;nobranch=1 \
           git://github.com/dgryski/go-farm.git;protocol=https;name=go-farm;destsuffix=${PN}-${PV}/src/github.com/dgryski/go-farm;nobranch=1 \
           git://github.com/karrick/godirwalk.git;protocol=https;name=godirwalk;destsuffix=${PN}-${PV}/src/github.com/karrick/godirwalk;nobranch=1 \
           git://github.com/labstack/gommon.git;protocol=https;name=gommon;destsuffix=${PN}-${PV}/src/github.com/labstack/gommon;nobranch=1 \
           git://github.com/markbates/errx.git;protocol=https;name=errx;destsuffix=${PN}-${PV}/src/github.com/markbates/errx;nobranch=1 \
           git://github.com/markbates/oncer.git;protocol=https;name=oncer;destsuffix=${PN}-${PV}/src/github.com/markbates/oncer;nobranch=1 \
           git://github.com/markbates/safe.git;protocol=https;name=safe;destsuffix=${PN}-${PV}/src/github.com/markbates/safe;nobranch=1 \
           git://github.com/mattn/go-colorable.git;protocol=https;name=go-colorable;destsuffix=${PN}-${PV}/src/github.com/mattn/go-colorable;nobranch=1 \
           git://github.com/mr-tron/base58.git;protocol=https;name=base58;destsuffix=${PN}-${PV}/src/github.com/mr-tron/base58;nobranch=1 \
           git://github.com/oasislabs/ed25519.git;protocol=https;name=ed25519;destsuffix=${PN}-${PV}/src/github.com/oasislabs/ed25519;nobranch=1 \
           git://github.com/valyala/fasttemplate.git;protocol=https;name=fasttemplate;destsuffix=${PN}-${PV}/src/github.com/valyala/fasttemplate;nobranch=1 \
           git://github.com/uber-go/atomic.git;protocol=https;name=atomic;destsuffix=${PN}-${PV}/src/go.uber.org/atomic;nobranch=1 \
           git://github.com/golang/sys.git;protocol=https;name=sys;destsuffix=${PN}-${PV}/src/golang.org/x/sys;nobranch=1 \
	   git://github.com/etcd-io/bbolt.git;protocol=https;name=bbolt;destsuffix=${PN}-${PV}/src/go.etcd.io/bbolt;nobranch=1 \
	   git://github.com/prometheus/client_golang.git;protocol=https;name=prometheus;destsuffix=${PN}-${PV}/src/github.com/prometheus/client_golang;nobranch=1 \
	   git://github.com/beorn7/perks.git;protocol=https;name=perks;destsuffix=${PN}-${PV}/src/github.com/beorn7/perks;nobranch=1 \
	   git://github.com/prometheus/client_model.git;protocol=https;name=client_model;destsuffix=${PN}-${PV}/src/github.com/prometheus/client_model;nobranch=1 \
	   git://github.com/prometheus/common.git;protocol=https;name=common;destsuffix=${PN}-${PV}/src/github.com/prometheus/common;nobranch=1 \
	   git://github.com/matttproud/golang_protobuf_extensions.git;protocol=https;name=golang_protobuf_extensions;destsuffix=${PN}-${PV}/src/github.com/matttproud/golang_protobuf_extensions;nobranch=1 \
	   git://github.com/prometheus/procfs.git;protocol=https;name=procfs;destsuffix=${PN}-${PV}/src/github.com/prometheus/procfs;nobranch=1 \
"

SRCREV_hornet = "v0.4.0"

# hornet deps
SRCREV_xxhash = "v2.1.1"
SRCREV_badger = "v2.0.1"
SRCREV_paho.mqtt = "0d940dd29fd24f905cd16b28b1209b4977b97e1a"
SRCREV_hmq = "55f1f1aa8001b422e4e648cf8240a2bdf0dbfd52"
SRCREV_gzip = "v0.0.1"
SRCREV_gin = "v1.5.0"
SRCREV_zmq4 = "v0.9.0"
SRCREV_packr = "v2.8.0"
SRCREV_go-github = "v17.0.0"
SRCREV_go-querystring = "v1.0.0"
SRCREV_go-version = "v1.2.0"
SRCREV_websocket = "v1.4.2"
SRCREV_hive.go = "06bf0dc5c0efb61bc7d11bd7425cd6cb8eaf7a02"
SRCREV_iota.go = "3dfaebe62d8b4037de292cd9c0bbd1a6027a9873"
SRCREV_echo = "v4.1.15"
SRCREV_mapstructure = "v1.2.2"
SRCREV_errors = "v0.9.1"
SRCREV_libcalico-go = "v3.9.0-0.dev"
SRCREV_gopsutil = "v2.20.2"
SRCREV_pflag = "v1.0.5"
SRCREV_net = "1c781a10960ae16c34a899a47d78ad79ab36fd61"
SRCREV_go-latest = "e3007ae9052ed85144087e7392e4c3fbc07962fa"
SRCREV_go-metro = "280f6062b5bc97ee9b9afe7f2ccb361e59845baa"
SRCREV_atomic = "v1.5.1"
SRCREV_prometheus = "v1.6.0"

# echo deps
SRCREV_jwt-go = "v3.2.0"
SRCREV_crypto = "38d8ce5564a5b71b2e3a00553993f1b9a7ae852f"
SRCREV_gommon = "v0.3.0"

# badger deps
SRCREV_go-humanize = "v1.0.0"
SRCREV_protobuf = "v1.3.1"
SRCREV_snappy = "v0.0.1"
SRCREV_zstd = "v1.4.1"
SRCREV_ristretto = "c1f00be0418e1e647efe10e5f1c3930db33fec98"
SRCREV_go-farm = "6a90982ecee230ff6cba02d5bd386acc030be9d3"

# gin deps
SRCREV_sse = "v0.1.0"
SRCREV_go-isatty = "v0.0.9"
SRCREV_json-iterator = "v1.1.7"
SRCREV_go-codec = "v1.1.7"
SRCREV_validator = "v9.29.1"

# packr deps
SRCREV_envy = "v1.7.0"
SRCREV_logger = "v1.0.0"
SRCREV_packd = "v0.3.0"
SRCREV_godirwalk = "v1.10.12"
SRCREV_errx = "v1.1.0"
SRCREV_oncer = "v1.0.0"
SRCREV_safe = "v1.0.1"

# envy deps
SRCREV_godotenv = "v1.3.0"
SRCREV_go-internal = "v1.1.0"

# logger deps
SRCREV_logrus = "v1.4.2"

# hive.go deps
SRCREV_viper = "v1.6.2"
SRCREV_zap = "v1.13.0"
SRCREV_base58 = "v1.1.3"
SRCREV_ed25519 = "29f6767a7c3efd210de1289dd6260a46b7e9d63d"
SRCREV_bbolt = "v1.3.4"

# viper deps
SRCREV_fsnotify = "v1.4.9"
SRCREV_hcl = "v1.0.0"
SRCREV_properties = "v1.8.1"
SRCREV_afero = "v1.1.2"
SRCREV_go-toml = "v1.2.0"
SRCREV_cast = "v1.3.0"
SRCREV_jwalterweatherman = "v1.0.0"
SRCREV_gotenv = "v1.2.0"
SRCREV_yaml = "v2.2.4"
SRCREV_ini.v1 = "v1.51.0"

# zmq4 deps
SRCREV_xerrors = "a985d3407aa71f30cf86696ee0a2f409709f22e1"
SRCREV_sync = "112230192c580c3556b8cee6403af37a4fc5f28c"

# validator deps
SRCREV_universal-translator = "v0.17.0"
SRCREV_go-urn = "v1.2.0"

# universal-translator deps
SRCREV_locales = "v0.13.0"

# hmq deps
SRCREV_sarama = "v1.23.0"
SRCREV_go-simplejson = "v0.5.0"
SRCREV_go-cache = "v2.1.0"
SRCREV_go.uuid = "v1.2.0"
SRCREV_fasthash = "a72b379d632eab4b49e4f4b2c765cfebf0a74796"
SRCREV_gjson = "v1.3.0"

# sarama deps
SRCREV_go-spew = "v1.1.1"
SRCREV_go-resiliency = "v1.1.0"
SRCREV_go-xerial-snappy = "776d5712da21bc4762676d614db1d8a64f4238b0"
SRCREV_queue = "v1.1.0"
SRCREV_gofork = "dc7c13fece037a4a36e2b3c69db4991498d30692"
SRCREV_lz4 = "315a67e90e415bcdaff33057da191569bf4d8479"
SRCREV_go-metrics = "3113b8401b8a98917cde58f8bbd42a1b1c03b1fd"
SRCREV_gokrb5 = "v7.2.3"

# gjson deps
SRCREV_match = "v1.0.1"
SRCREV_pretty = "v1.0.0"

# zap deps
SRCREV_multierr = "v1.3.0"

# afero deps
SRCREV_text = "v0.3.2"

# gokrb5 deps
SRCREV_go-uuid = "v1.0.1"
SRCREV_aescts = "v1.0.1"
SRCREV_dnsutils = "v1.0.1"
SRCREV_rpc = "v1.1.0"

# gommon deps
SRCREV_go-colorable = "v0.1.2"
SRCREV_fasttemplate = "v1.0.1"

# fsnotify deps
SRCREV_sys = "aed5e4c7ecf9f069775e08834fb724544628d38d"

# prometheus deps
SRCREV_perks = "v1.0.1"
SRCREV_client_model = "v0.2.0"
SRCREV_common = "v0.9.1"
SRCREV_procfs = "v0.0.11"

# common deps
SRCREV_golang_protobuf_extensions = "v1.0.1"
