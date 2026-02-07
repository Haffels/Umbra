# Havlock

> Your files. Your encryption. Your control.

A cross-platform encrypted backup and sync tool that puts privacy first. Think Dropbox, but you own the keys.

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C++-20-00599C.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/status-in%20development-yellow.svg)]()

## What is Havlock?

Havlock is an encrypted backup solution that ensures your data remains private, even when stored in the cloud. All encryption happens locally on your device before any data leaves your system.

**Key Principles:**
- **Zero-knowledge**: Your files are encrypted before they leave your device
- **You control the keys**: No backdoors, no key escrow, no trust required
- **Open source**: Transparent security you can audit yourself

## Features

### Current
- **Military-grade encryption** - AES-256-GCM with secure key derivation
- **Local file encryption** - Protect sensitive files on your device
- **Strong key management** - PBKDF2/Argon2 password-based encryption

### Planned
- **Cloud sync** - Google Drive, Dropbox, S3, and network drives
- **Incremental backups** - Only sync what's changed
- **Version history** - Restore previous file versions
- **Cross-platform** - Windows, Linux, macOS support
- **Dual interface** - Command-line and GUI options
- **Secure sharing** - Share encrypted files with specific recipients
- **Smart compression** - Reduce storage usage before encryption
- **Deduplication** - Never backup the same data twice
- **Resumable uploads** - Pick up where you left off

## Why Havlock?

**For Privacy-Conscious Users:**
- Cloud providers can't read your data
- Protection against data breaches
- Compliance with data protection regulations

**For Students & Developers:**
- Secure backups of coursework and projects
- Version control for non-code files
- Learn practical cryptography implementation

**For Everyone:**
- Free and open-source alternative to commercial solutions
- No subscription fees or data limits
- Full control over your backup infrastructure

## Quick Start

```bash
# Clone the repository
git clone https://github.com/haffels/Havlock.git
cd Havlock

# Build (instructions coming soon)
mkdir build && cd build
cmake ..
make

# Encrypt a file
./Havlock encrypt myfile.txt

# Decrypt a file
./Havlock decrypt myfile.txt.Havlock
```

## Development Roadmap

### Phase 1: Core Encryption (Months 1-2)
- [x] Project setup and repository structure
- [ ] AES-256-GCM implementation
- [ ] RSA/Curve25519 key exchange
- [ ] PBKDF2/Argon2 key derivation
- [ ] Secure random number generation
- [ ] Unit tests for crypto primitives

### Phase 2: File Management (Months 2-3)
- [ ] File chunking system
- [ ] Compression engine
- [ ] Metadata encryption
- [ ] Deduplication logic
- [ ] Local file monitoring

### Phase 3: Sync Engine (Months 3-4)
- [ ] Cloud provider API integration
- [ ] Change detection system
- [ ] Conflict resolution
- [ ] Bandwidth optimization
- [ ] Progress tracking

### Phase 4: Advanced Features (Months 4-5)
- [ ] Cross-platform GUI (Qt)
- [ ] Selective sync
- [ ] Secure file sharing
- [ ] Two-factor authentication
- [ ] Emergency recovery system
- [ ] Multi-device coordination

## Technical Architecture

**Encryption Stack:**
- **Symmetric**: AES-256-GCM for file content
- **Asymmetric**: RSA-4096 or Curve25519 for key exchange
- **Key Derivation**: Argon2id for password-based keys
- **Integrity**: Built-in authentication with GCM mode

**Security Features:**
- Zero-knowledge architecture
- Client-side encryption only
- Secure memory wiping
- Constant-time cryptographic operations
- Protection against timing attacks

## Contributing

This is currently a learning project, but contributions and suggestions are welcome! Feel free to:
- Open issues for bugs or feature requests
- Submit pull requests
- Suggest improvements to the cryptographic design
- Help with documentation

## Learning Goals

This project is designed to teach:
- Practical cryptography implementation
- Secure software development practices
- Cross-platform C++ development
- API integration with cloud services
- Building production-quality tools
- Security auditing and threat modeling

## Security Notice

**This software is currently under development and should not be used for protecting sensitive data in production environments.**

While built with security best practices in mind, this is an educational project. For production use, please wait for:
- Independent security audit
- Stable release (v1.0)
- Comprehensive testing

## License

MIT License - see [LICENSE](LICENSE) file for details

## Acknowledgments

- Inspired by modern zero-knowledge storage solutions
- Built as preparation for cybersecurity studies
- Learning from the cryptography community

## Contact

Questions? Suggestions? Security concerns?
- Open an issue on GitHub

---

**Building the future of private backups, one commit at a time.**