from bitcoin_client.hwi.serialization import CTransaction

def test_verify(cmd):
    firstTransaction = True
    inputIndex = 0
    chipInputs = [
        {'trustedInput': True,
         'value': bytearray(b'2\x00]\x97\xf9\xb3(O$\x837\x8b\xbb\xe6T|\x99\x0e#^\xb2\x8c\x11l\x16h\x10Me\x84\x97\xfcl\xe7\xeca\x00\x00\x00\x00\xe0\x0f\x97\x00\x00\x00\x00\x00\xf0\xe0\r\x89\xf2\x84\x1d\x06'),
         'sequence': 'feffffff'
         },
        {'trustedInput': True,
         'value': bytearray(b'2\x00\xedSc\x1f\xaay%T\xb0\x92\xfb\xd0\xa1\xc2\xdeC\x81\x01\xe9\n\xad\xd5Vo\x06\xb4e4dZ\xb4\x8b-\xb1\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe4\x9c1\x9cJ\xc1\xe9\x0b'),
         'sequence': 'feffffff'}
    ]
    redeemScripts = [
        b'v\xa9\x14\xb4\x8d\xcc\xf9\xce\x8b\x8a\xfaT\xb9T\x1d<R\xa8\x00\x1b\x89\x90#\x88\xac',
        b'v\xa9\x140\x85)\xa1\xcf~\xc48\xd2}\x12c\x8b\x8e\x97\xa1\xd4!M\x00\x88\xac\xc0\x15rvnt\x08SCAMCOIN\x00\xe4\x0bT\x02\x00\x00\x00u'
    ]
    txVersion = 2

    while inputIndex < len(redeemScripts):
        inputIndex += 1