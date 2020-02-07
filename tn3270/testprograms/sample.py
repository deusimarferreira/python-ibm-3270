#!/usr/bin/python
#-*- coding: utf-8

#import inspect
import tn3270

#class Host(tn3270.Session):
#
#    def __init__(self):
#
#        super().__init__(":a")
#        print("Using tn3270 version " + self.version + " revision " + self.revision)
#
#    def reconnect(self):
#        if super().reconnect.activatable:
#            print("Reconnecting...")
#            super().reconnect().wait(10)
#
#host = Host()
#host.reconnect()

print("Testing python module")

print("Using TN3270 Version " + tn3270.version())
#print(tn3270.py3270)

session = tn3270.Session("")

session.connect("tn3270://zos.efglobe.com:telnet?crl_preferred_protocol=tls")
#session.connect("tn3270s://hod.serpro.gov.br:23000?luname=AWVR8462")
#session.connect("tn3270s://hod.serpro.gov.br:23000")
#session.connect("tn3270s://hod.serpro.gov.br:23000")
session.timeout = 10

print("Using tn3270 version " + session.version + " revision " + session.revision)

print(session.cstate)
print(session.width)
print(session.connected)

print(session.reconnect)

#
# Can reconnect? If yes do it!
#
if session.reconnect.activatable:
    print("Reconnecting...")
    session.reconnect().wait(10)

print(session.connected)
print(session.find('sistema'))
print(session.count('sistema'))
print('LUName ==> ' + session.associated_lu)

print('----------------------')
print(dir(session))
print('----------------------')

print('==> ' + session.get(14,19,38))

print("-----------------------------------------------------------------------")
print(session)
print("-----------------------------------------------------------------------")

#session.enter().wait(21,21,"Enter your choice==>")
session.set("NVAS")
session.enter()

print("-----------------------------------------------------------------------")
print(session)
print("-----------------------------------------------------------------------")

session.set(15, 29, "deusimar")
session.set(16, 29, "q1w2e3")
session.enter()
#session.pf(15)


print("-----------------------------------------------------------------------")
print(session)
print("-----------------------------------------------------------------------")

input("Press enter to exit")