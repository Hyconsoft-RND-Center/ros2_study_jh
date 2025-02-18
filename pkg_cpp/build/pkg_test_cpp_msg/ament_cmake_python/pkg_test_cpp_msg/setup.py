from setuptools import find_packages
from setuptools import setup

setup(
    name='pkg_test_cpp_msg',
    version='0.0.0',
    packages=find_packages(
        include=('pkg_test_cpp_msg', 'pkg_test_cpp_msg.*')),
)
