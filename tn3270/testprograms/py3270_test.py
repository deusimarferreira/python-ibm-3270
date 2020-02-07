from py3270 import Emulator

# use x3270 so you can see what is going on
em = Emulator(visible=True)

# or not (uses s3270)
#em = Emulator()

em.connect('zos.efglobe.com')
#em.fill_field(17, 23, 'mylogin', 8)
#em.fill_field(18, 23, 'mypass', 8)
#em.send_enter()

# if your host unlocks the keyboard before truly being ready you can use:
em.wait_for_field()

# maybe look for a status message
if not em.string_found(1, 2, 'login succesful'):
    abort()

# do something useful

# disconnect from host and kill subprocess
em.terminate()