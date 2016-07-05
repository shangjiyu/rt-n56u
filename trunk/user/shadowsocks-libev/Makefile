SRC_NAME=shadowsocks-libev-ra-2.4.7

CFLAGS += -ffunction-sections -fdata-sections
LDFLAGS += -Wl,-flto

all: config_test
	$(MAKE) -C $(SRC_NAME)

config_test:
	( if [ -f ./config_done ]; then \
		echo "the same configuration"; \
	else \
		make configure && touch config_done; \
	fi )

configure:
	( cd $(SRC_NAME) ; \
	./configure \
		--disable-nls \
		--disable-ssp \
		--host=$(HOST_TARGET) \
		--build=$(HOST_BUILD) ; \
	)

clean:
	if [ -f $(SRC_NAME)/Makefile ] ; then \
		$(MAKE) -C $(SRC_NAME) distclean ; \
	fi ; \
	rm -f config_done

romfs:
	$(ROMFSINST) $(SRC_NAME)/src/ss-local /usr/bin/ss-local
	$(ROMFSINST) $(SRC_NAME)/src/ss-server /usr/bin/ss-server
	$(ROMFSINST) $(SRC_NAME)/src/ss-tunnel /usr/bin/ss-tunnel
	$(ROMFSINST) $(SRC_NAME)/src/ss-redir /usr/bin/ss-redir
	$(ROMFSINST) $(SRC_NAME)/src/ss-nat /usr/bin/ss-nat
