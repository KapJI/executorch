from abc import ABC, abstractmethod
from typing import Dict, List, Tuple, Union

from executorch.exir._serialize._cord import Cord

from executorch.exir.schema import Tensor

# Abstract base class that data serializers should adhere to.
class DataSerializer(ABC):
    @abstractmethod
    def __init__(self) -> None:
        """
        This initializer may be overridden in derived classes to hold
        the data required for serialization, eg. configurations.
        """
        pass    
    
    @abstractmethod
    def serialize_tensors(self, 
        tensors: Dict[str, int],
        tensor_buffer: List[bytes],
        tensor_metadata: Dict[str, Tensor],
    ) -> Union[Cord, bytes, bytearray]:
        """
        Serializes a list of tensor metadata and tensors emitted by ExecuTorch
        into a binary blob.
        """
        raise NotImplementedError("serialize_data")

    @abstractmethod
    def deserialize_tensors(self, blob: Union[Cord, bytes, bytearray]) -> Tuple[Dict[str, int], List[bytes], Dict[str, Tensor]]:
        """
        Deserializes a blob into a list of tensor metadata and tensors.
        """
        raise NotImplementedError("deserialize_data")
