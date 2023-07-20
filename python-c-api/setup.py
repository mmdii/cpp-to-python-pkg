from setuptools import setup, Extension

extension = Extension(
    "primes",
    sources=["primes.c"],
    libraries=["prime"],
    library_dirs=["."],
)

setup(
    name="primes",
    version="1.0.0",
    author="Mohammad Mohammadi",
    author_email="mohammad.mohammadii1997@gmail.com",
    description="This Package will calculate prime numbers",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    url="https://github.com/mmdii/cpp-to-python-pkg",
    packages=["primes"],
    ext_modules=[extension],
    data_files=[("", ["primes.so"])],
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    install_requires=[
        "numpy",
        "pandas",
        "matplotlib",
    ],
)